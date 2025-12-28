#ifndef MANAGER_DEFS_H
#define MANAGER_DEFS_H

#include "employee_base.h"
#include "../Schedule/schedule_mgr.h"

class ScheduleMgr;
class Coach;

class Manager : public EmployeeBase
{
public:
    Manager(std::string fullName,
            unsigned int ageValue,
            char sexChar,
            std::string birthDate,
            bool passkeyAccess,
            PassKey* keyPtr,
            bool hasSubscription,
            double balanceAmount,
            double bodyWeight,
            unsigned int bodyHeight,
            unsigned int expYears,
            double payRate,
            std::string contactPhone);

    void updateStartTime(ScheduleMgr& sched, unsigned int newTime);
    void updateEndTime(ScheduleMgr& sched, unsigned int newTime);
    void scheduleDuty(Coach& coachRef);
    void removeFromDuty(Coach& coachRef);
};

#endif
