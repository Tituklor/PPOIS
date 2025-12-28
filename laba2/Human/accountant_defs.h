#ifndef ACCOUNTANT_DEFS_H
#define ACCOUNTANT_DEFS_H

#include <vector>

#include "employee_base.h"

class Membership;
class PassKey;
class EmployeeBase;

class Accountant : public EmployeeBase
{
public:
    Accountant(std::string acctName, unsigned int acctAge,
               char acctGender, std::string acctBirthDate,
               bool keyBindingAllowed, PassKey* acctKey,
               bool hasActiveSub, double acctFunds,
               double acctWeight, unsigned int acctHeight,
               unsigned int acctExperience, double acctSalary,
               std::string acctPhone);

    double calculate_total_payroll(const std::vector<EmployeeBase*>& staff_list) const;
    void update_employee_salary(EmployeeBase* worker, double new_pay_rate);
};

#endif
