// core/Person/Person.cpp
#include "Person.h"
#include "../../config/Config.h"
#include "../../exceptions/InvalidAgeException.h"
#include "../../exceptions/InvalidNameException.h"
#include "../../exceptions/InvalidPhoneNumberException.h"
#include "../../exceptions/InvalidEmailException.h"

Person::Person(const std::string& name, int age,
               const std::string& phoneNumber, const std::string& email)
        : name_(name), age_(age), phoneNumber_(phoneNumber), email_(email) {
    if (name_.empty()) {
        throw InvalidNameException(name_);
    }
    if (age_ < Config::MIN_MEMBER_AGE || age_ > Config::MAX_MEMBER_AGE) {
        throw InvalidAgeException(age_);
    }
    if (phoneNumber_.empty() || phoneNumber_.size() < 10) {
        throw InvalidPhoneNumberException(phoneNumber_);
    }
    if (email_.find('@') == std::string::npos) {
        throw InvalidEmailException(email_);
    }
}

std::string Person::getName() const { return name_; }
void Person::setName(const std::string& name) {
    if (name.empty()) throw InvalidNameException(name);
    name_ = name;
}

int Person::getAge() const { return age_; }
void Person::setAge(int age) {
    if (age < Config::MIN_MEMBER_AGE || age > Config::MAX_MEMBER_AGE) {
        throw InvalidAgeException(age);
    }
    age_ = age;
}

std::string Person::getPhoneNumber() const { return phoneNumber_; }
void Person::setPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.empty() || phoneNumber.size() < 10) {
        throw InvalidPhoneNumberException(phoneNumber);
    }
    phoneNumber_ = phoneNumber;
}

std::string Person::getEmail() const { return email_; }
void Person::setEmail(const std::string& email) {
    if (email.find('@') == std::string::npos) {
        throw InvalidEmailException(email);
    }
    email_ = email;
}