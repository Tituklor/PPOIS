// core/Coach/Coach.cpp
#include "Coach.h"
#include "../../config/Config.h"

Coach::Coach(const std::string& name, int age,
             const std::string& phoneNumber, const std::string& email,
             int id, const std::string& specialization)
        : Person(name, age, phoneNumber, email), id_(id), specialization_(specialization) {}

int Coach::getId() const {
    return id_;
}

std::string Coach::getSpecialization() const {
    return specialization_;
}

void Coach::setSpecialization(const std::string& specialization) {
    specialization_ = specialization;
}

double Coach::getSalary() const {
    return Config::COACH_SALARY_BASE;
}