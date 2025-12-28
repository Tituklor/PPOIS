#include "manager_defs.h"
#include "coach_defs.h"

Manager::Manager(std::string fullName, unsigned int ageValue, char sexChar,
                 std::string birthDate, bool passkeyAccess, PassKey* keyPtr,
                 bool hasSubscription, double balanceAmount, double bodyWeight,
                 unsigned int bodyHeight, unsigned int expYears, double payRate,
                 std::string contactPhone)
        : EmployeeBase(fullName, ageValue, sexChar, birthDate, passkeyAccess,
                       keyPtr, hasSubscription, balanceAmount, bodyWeight,
                       bodyHeight, expYears, payRate, contactPhone)
{
}

void Manager::updateStartTime(ScheduleMgr& sched, unsigned int newTime)
{
    sched.open_time = newTime;
}

void Manager::updateEndTime(ScheduleMgr& sched, unsigned int newTime)
{
    sched.close_time = newTime;
}

void Manager::scheduleDuty(Coach& coachRef)
{
    coachRef.on_duty = true;
}

void Manager::removeFromDuty(Coach& coachRef)
{
    coachRef.on_duty = false;
}
