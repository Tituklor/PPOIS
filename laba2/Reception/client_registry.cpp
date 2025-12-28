#include "client_registry.h"
#include "../Human/error_defs.h"

void ClientRegistry::register_person(PersonBase* person)
{
    if (person->active_membership) {
        registered_clients.push_back(person);
    } else {
        throw SubscriptionIssueError("У клиента еще нет абонемента");
    }
}

void ClientRegistry::decrement_all_days()
{
    for (size_t idx = 0; idx < registered_clients.size(); idx++) {
        if (registered_clients[idx]->active_membership->remaining_days > 0) {
            registered_clients[idx]->active_membership->remaining_days--;
            if (registered_clients[idx]->active_membership->remaining_days == 0) {
                registered_clients[idx]->active_membership->make_empty();
            }
        }
    }
}
