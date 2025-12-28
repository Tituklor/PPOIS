#include "employee_base.h"

EmployeeBase::EmployeeBase(std::string personName, unsigned int personAge, char personSex,
                           std::string personBirth, bool key_access_enabled, PassKey* access_key,
                           bool membership_status, double account_balance, double body_mass,
                           unsigned int body_stature, unsigned int years_of_service, double pay_rate,
                           std::string contact_number)
        : PersonBase(personName, personAge, personSex, personBirth, key_access_enabled,
                     access_key, membership_status, account_balance, body_mass, body_stature),
          years_of_service(years_of_service), pay_rate(pay_rate), contact_number(contact_number)
{
}

void EmployeeBase::update_pay_rate(double new_rate)
{
    pay_rate = new_rate;
}

void EmployeeBase::update_contact(std::string new_number)
{
    contact_number = new_number;
}

void EmployeeBase::update_service_years(unsigned int service_years)
{
    years_of_service = service_years;
}

double EmployeeBase::retrieve_pay_rate() const
{
    return pay_rate;
}

std::string EmployeeBase::retrieve_contact() const
{
    return contact_number;
}

unsigned int EmployeeBase::retrieve_service_years() const
{
    return years_of_service;
}
