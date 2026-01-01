// core/Staff/Staff.cpp
#include "Staff.h"
#include "../../config/Config.h"

Staff::Staff(const std::string& name, int age,
             const std::string& phoneNumber, const std::string& email,
             int id, const std::string& position)
        : Person(name, age, phoneNumber, email), id_(id), position_(position) {}

int Staff::getId() const {
    return id_;
}

std::string Staff::getPosition() const {
    return position_;
}

void Staff::setPosition(const std::string& position) {
    position_ = position;
}

double Staff::getSalary() const {
    return Config::STAFF_SALARY_BASE;
}