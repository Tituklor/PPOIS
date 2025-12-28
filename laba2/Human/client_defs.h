#ifndef CLIENT_DEFS_H
#define CLIENT_DEFS_H

#include "person_base.h"

class Coach;

class Client : public PersonBase
{
    Coach* assigned_coach;

public:
    Client(std::string clientName,
           unsigned int clientAge,
           char clientSex,  // 'f' = female, 'm' = male
           std::string clientBirthDate,
           bool lockerKeyAccess,
           PassKey* clientKey,
           bool activeMembership,
           double clientBalance,
           double clientWeight,
           unsigned int clientHeight,
           Coach* assigned_coach);

    std::string retrieve_coach_name();
    void assign_coach(Coach* new_coach);
};

#endif
