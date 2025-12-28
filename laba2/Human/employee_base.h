#ifndef EMPLOYEE_BASE_H
#define EMPLOYEE_BASE_H

#include <string>
#include "person_base.h"

class PassKey;
class Accountant;

class EmployeeBase : public PersonBase
{
    friend class Accountant;

protected:
    unsigned int years_of_service;
    double pay_rate;
    std::string contact_number;

private:
    double salary;

public:
    EmployeeBase(std::string personName,
                 unsigned int personAge,
                 char personSex,  // 'f' = female, 'm' = male
                 std::string personBirth,
                 bool key_access_enabled,
                 PassKey* access_key,
                 bool membership_status,
                 double account_balance,
                 double body_mass,
                 unsigned int body_stature,
                 unsigned int years_of_service,
                 double pay_rate,
                 std::string contact_number);

    double retrieve_pay_rate() const;
    unsigned int retrieve_service_years() const;
    std::string retrieve_contact() const;

    void update_pay_rate(double new_rate);
    void update_contact(std::string new_number);
    void update_service_years(unsigned int service_years);
};

#endif
