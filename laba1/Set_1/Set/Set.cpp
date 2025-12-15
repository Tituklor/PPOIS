/**
 * @file Set.cpp
 * @brief Реализация класса Set
 * @date 2025
 */
#include "Set.h"
#include <algorithm>
#include <cctype>
#include <stack>
#include <iomanip>


Set::Element::Element(const std::string& str)
        : isString(true), strValue(str), setValue(nullptr) {}

Set::Element::Element(std::shared_ptr<Set> set)
        : isString(false), strValue(""), setValue(set) {}

bool Set::Element::operator==(const Element& other) const {
    if (isString != other.isString) return false;
    if (isString) return strValue == other.strValue;
    if (!setValue || !other.setValue) return false;
    return *setValue == *other.setValue;
}

bool Set::Element::operator!=(const Element& other) const {
    return !(*this == other);
}


Set::Element makeString(const std::string& str) {
    return Set::Element(str);
}

Set::Element makeSet(std::shared_ptr<Set> set) {
    return Set::Element(set);
}


Set::Set() = default;

Set::Set(const Set& other) : elements_(other.elements_) {
    for (auto& elem : elements_) {
        if (!elem.isString && elem.setValue) {
            elem.setValue = elem.setValue->deepCopy();
        }
    }
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        Set temp(other);
        std::swap(elements_, temp.elements_);
    }
    return *this;
}

bool Set::empty() const {
    return elements_.empty();
}

size_t Set::size() const {
    return elements_.size();
}

bool Set::hasElement(const Element& elem) const {
    return std::any_of(elements_.begin(), elements_.end(),
                       [&elem](const Element& e) { return e == elem; });
}

bool Set::contains(const Element& elem) const {
    return hasElement(elem);
}

Set& Set::insert(const Element& elem) {
    if (!hasElement(elem)) {
        elements_.push_back(elem);
    }
    return *this;
}

bool Set::erase(const Element& elem) {
    auto it = std::remove_if(elements_.begin(), elements_.end(),
                             [&elem](const Element& e) { return e == elem; });
    if (it != elements_.end()) {
        elements_.erase(it, elements_.end());
        return true;
    }
    return false;
}


Set Set::operator+(const Set& other) const {
    Set result(*this);
    for (const auto& elem : other.elements_) {
        result.insert(elem);
    }
    return result;
}

Set& Set::operator+=(const Set& other) {
    for (const auto& elem : other.elements_) {
        insert(elem);
    }
    return *this;
}

Set Set::operator*(const Set& other) const {
    Set result;
    for (const auto& elem : elements_) {
        if (other.hasElement(elem)) {
            result.insert(elem);
        }
    }
    return result;
}

Set& Set::operator*=(const Set& other) {
    Set temp = *this * other;
    elements_ = std::move(temp.elements_);
    return *this;
}

Set Set::operator-(const Set& other) const {
    Set result;
    for (const auto& elem : elements_) {
        if (!other.hasElement(elem)) {
            result.insert(elem);
        }
    }
    return result;
}

Set& Set::operator-=(const Set& other) {
    Set temp = *this - other;
    elements_ = std::move(temp.elements_);
    return *this;
}

Set Set::powerSet() const {
    if (empty()) {
        Set result;
        result.insert(makeString(""));
        return result;
    }

    Set result;
    size_t numSubsets = 1 << std::min(size(), size_t(10)); // Ограничение для производительности
    for (size_t i = 0; i < numSubsets; ++i) {
        Set subset;
        for (size_t j = 0; j < size(); ++j) {
            if (i & (1 << j)) {
                subset.insert(elements_[j]);
            }
        }
        result.insert(makeSet(std::make_shared<Set>(subset)));
    }
    return result;
}


void Set::parseString(const std::string& str, size_t& pos) {

    while (pos < str.size() && std::isspace(str[pos])) ++pos;
    if (pos >= str.size() || str[pos] != '{') return;
    ++pos;

    while (pos < str.size() && str[pos] != '}') {
        while (pos < str.size() && std::isspace(str[pos])) ++pos;
        if (pos >= str.size()) break;

        if (str[pos] == '{') {

            Set nested;
            size_t nestedPos = pos;
            nested.parseString(str, nestedPos);
            if (nestedPos > pos) {
                insert(makeSet(std::make_shared<Set>(nested)));
                pos = nestedPos;
            }
        } else if (str[pos] == '"' || std::isalpha(str[pos]) || std::isdigit(str[pos])) {
            // Строка
            size_t start = pos;
            while (pos < str.size() &&
                   str[pos] != ',' && str[pos] != '}' &&
                   !std::isspace(str[pos])) {
                ++pos;
            }
            std::string token = str.substr(start, pos - start);
            if (!token.empty()) {
                insert(makeString(token));
            }
        }
        
        while (pos < str.size() && std::isspace(str[pos])) ++pos;
        if (pos < str.size() && str[pos] == ',') ++pos;
    }

    if (pos < str.size() && str[pos] == '}') ++pos;
}

Set::Set(const std::string& str) {
    size_t pos = 0;
    parseString(str, pos);
}


bool Set::operator==(const Set& other) const {
    if (size() != other.size()) return false;
    for (const auto& elem : elements_) {
        if (!other.hasElement(elem)) return false;
    }
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}

std::shared_ptr<Set> Set::deepCopy() const {
    return std::make_shared<Set>(*this);
}


std::ostream& operator<<(std::ostream& os, const Set& set) {
    os << "{";
    for (size_t i = 0; i < set.elements_.size(); ++i) {
        if (i > 0) os << ", ";
        const auto& elem = set.elements_[i];
        if (elem.isString) {
            os << elem.strValue;
        } else if (elem.setValue) {
            os << *elem.setValue;
        }
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Set& set) {
    std::string input;
    std::getline(is, input, '}');
    set = Set("{" + input + "}");
    return is;
}
