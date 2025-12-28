#include "accountant_defs.h"

Accountant::Accountant(std::string acctName, unsigned int acctAge,
                       char acctGender, std::string acctBirthDate,
                       bool keyBindingAllowed, PassKey* acctKey,
                       bool hasActiveSub, double acctFunds,
                       double acctWeight, unsigned int acctHeight,
                       unsigned int acctExperience, double acctSalary,
                       std::string acctPhone)
        : EmployeeBase(acctName, acctAge, acctGender, acctBirthDate,
                       keyBindingAllowed, acctKey, hasActiveSub, acctFunds,
                       acctWeight, acctHeight, acctExperience, acctSalary, acctPhone)
{
}

double Accountant::calculate_total_payroll(const std::vector<EmployeeBase*>& staff_list) const
{
    double total_pay = 0.0;
    for (size_t idx = 0; idx < staff_list.size(); ++idx) {
        total_pay += staff_list[idx]->salary;
    }
    return total_pay;
}

void Accountant::update_employee_salary(EmployeeBase* worker, double new_pay_rate)
{
    worker->salary = new_pay_rate;
}
