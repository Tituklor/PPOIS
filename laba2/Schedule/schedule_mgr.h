#ifndef SCHEDULE_MGR_H
#define SCHEDULE_MGR_H

#include <string>
#include "../Human/manager_defs.h"
#include "../Human/error_defs.h"

class ScheduleMgr
{

    friend class Manager;

    unsigned int start_hour;
    unsigned int end_hour;
private:
    std::string open_time;   // ✅
    std::string close_time;  // ✅

public:
    ScheduleMgr();
    ScheduleMgr(unsigned int start_hour, unsigned int end_hour);

    unsigned int retrieve_start_hour();
    unsigned int retrieve_end_hour();
};

#endif
