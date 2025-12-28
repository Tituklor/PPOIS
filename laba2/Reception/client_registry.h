#ifndef CLIENT_REGISTRY_H
#define CLIENT_REGISTRY_H

#include <vector>
#include "membership_defs.h"
#include "../Human/person_base.h"

class PersonBase;
class FrontDeskStaff;

class ClientRegistry
{
public:
    void add_client(PersonBase& person);
    void change_remaining_days(PersonBase& person, int days);

    friend class FrontDeskStaff;

    std::vector<PersonBase*> registered_clients;

    void register_person(PersonBase* person);
    void decrement_all_days();
};

#endif
