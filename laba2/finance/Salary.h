// finance/Salary.h
#ifndef SPORTCLUB_SALARY_H
#define SPORTCLUB_SALARY_H

#include <string>

class Salary {
public:
    Salary(int personId, double baseAmount, const std::string& role);

    int getPersonId() const;
    double getBaseAmount() const;
    double getTotalAmount() const; // base + bonus (later)
    std::string getRole() const;

private:
    int personId_;
    double baseAmount_;
    std::string role_;
};

#endif // SPORTCLUB_SALARY_H