#include "schedule_mgr.h"

ScheduleMgr::ScheduleMgr() : start_hour(7u), end_hour(23u)
{
}

ScheduleMgr::ScheduleMgr(unsigned int start_hour, unsigned int end_hour)
        : start_hour(start_hour), end_hour(end_hour)
{
    if (start_hour > end_hour) {
        throw InvalidTimeRangeError("Время закрытия меньше времени открытия");
    }
    if (start_hour > 23 || start_hour < 0 || end_hour > 23 || end_hour < 0) {
        throw InvalidTimeError("В сутках 24 часа (от 0 до 23)");
    }
}

unsigned int ScheduleMgr::retrieve_start_hour()
{
    return start_hour;
}

unsigned int ScheduleMgr::retrieve_end_hour()
{
    return end_hour;
}
