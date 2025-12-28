#include "client_defs.h"
#include "coach_defs.h"
#include "error_defs.h"
#include "../Reception/membership_defs.h"

Client::Client(std::string clientName, unsigned int clientAge, char clientSex,
               std::string clientBirthDate, bool lockerKeyAccess, PassKey* clientKey,
               bool activeMembership, double clientBalance, double clientWeight,
               unsigned int clientHeight, Coach* assigned_coach)
        : PersonBase(clientName, clientAge, clientSex, clientBirthDate, lockerKeyAccess,
                     clientKey, activeMembership, clientBalance, clientWeight, clientHeight),
          assigned_coach(assigned_coach)
{
}

std::string Client::retrieve_coach_name()
{
    if (assigned_coach) {
        return assigned_coach->get_name();
    } else {
        throw TrainerAssignmentError("Нет назначенного тренера");
    }
}

void Client::assign_coach(Coach* new_coach)
{
    assigned_coach = new_coach;
}
