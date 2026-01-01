// finance/Salary.cpp
#include "Salary.h"

Salary::Salary(int personId, double baseAmount, const std::string& role)
        : personId_(personId), baseAmount_(baseAmount), role_(role) {}

int Salary::getPersonId() const {
    return personId_;
}

double Salary::getBaseAmount() const {
    return baseAmount_;
}

double Salary::getTotalAmount() const {
    // For now — no bonuses
    return baseAmount_;
}

std::string Salary::getRole() const {
    return role_;
}