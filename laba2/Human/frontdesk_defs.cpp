#include "frontdesk_defs.h"
#include "person_base.h"
#include "../Reception/client_registry.h"

FrontDeskStaff::FrontDeskStaff(std::string staff_name, unsigned int staff_age,
                               char staff_gender, std::string staff_birth,
                               bool key_link_perm, PassKey* staff_key,
                               bool staff_has_sub, double staff_balance,
                               double staff_weight, unsigned int staff_height,
                               unsigned int staff_exp, double staff_salary,
                               std::string staff_phone, KeyRack* key_storage,
                               ClientRegistry* client_database, FrontDesk* frontdesk_station)
        : EmployeeBase(staff_name, staff_age, staff_gender, staff_birth, key_link_perm,
                       staff_key, staff_has_sub, staff_balance, staff_weight, staff_height,
                       staff_exp, staff_salary, staff_phone),
          key_storage(key_storage), key_to_distribute(nullptr), key_to_return(nullptr),
          current_membership(nullptr), client_database(client_database),
          frontdesk_station(frontdesk_station)
{
}

void FrontDeskStaff::collect_client_membership(PersonBase& person)
{
    if (person.active_membership) {
        current_membership = person.active_membership;
        person.membership_active = true;
    } else {
        throw SubscriptionIssueError("У клиента нет абонемента");
    }
}

void FrontDeskStaff::generate_client_membership(PersonBase& person, int session_limit,
                                                int duration_days, Fitness* fitness_area,
                                                Gym* gym_area, Sauna* sauna_area,
                                                SwimmingPool* pool_area, WrestlingRing* ring_area)
{
    if (!current_membership) {
        if (!person.active_membership) {
            current_membership = new Membership(person, session_limit, duration_days,
                                                fitness_area, gym_area, sauna_area,
                                                pool_area, ring_area);
            collect_client_membership(person);
        } else {
            throw SubscriptionIssueError("У клиента уже есть абонемент");
        }
    } else {
        throw SubscriptionIssueError("Обслуживается другой клиент");
    }
}

void FrontDeskStaff::generate_client_membership(PersonBase& person)
{
    if (!current_membership) {
        if (!person.active_membership) {
            current_membership = new Membership(person);
            collect_client_membership(person);
        } else {
            throw SubscriptionIssueError("У клиента уже есть абонемент");
        }
    } else {
        throw SubscriptionIssueError("Обслуживается другой клиент");
    }
}

void FrontDeskStaff::register_client(PersonBase& person)
{
    client_database->add_client(&person);
}

void FrontDeskStaff::process_payment_for_membership()
{
    double membership_cost = current_membership->price();
    if (current_membership->owner->account_balance < membership_cost) {
        throw InsufficientFundsError("Недостаточно средств");
    }
    current_membership->owner->account_balance -= membership_cost;
    frontdesk_station->bank += membership_cost;
    current_membership->remaining_days = current_membership->validality_period;
    current_membership->remaining_sessions = current_membership->initial_num_of_sessions;
}

bool FrontDeskStaff::validate_sessions_and_duration()
{
    if (current_membership) {
        return current_membership->remaining_days > 0 && current_membership->remaining_sessions > 0;
    } else {
        throw SubscriptionIssueError("Нет клиентского абонемента на руках");
    }
}

void FrontDeskStaff::decrement_session_count()
{
    current_membership->remaining_sessions--;
    if (current_membership->remaining_sessions == 0) {
        clear_membership();
    }
}

void FrontDeskStaff::clear_membership()
{
    current_membership->make_empty();
}

bool FrontDeskStaff::verify_client_membership(PersonBase& person)
{
    return person.active_membership;
}

void FrontDeskStaff::include_gym_access()
{
    current_membership->gym = frontdesk_station->gym;
    current_membership->departments = true;
}

void FrontDeskStaff::include_fitness_access()
{
    current_membership->fitness = frontdesk_station->fitness;
    current_membership->departments = true;
}

void FrontDeskStaff::include_sauna_access()
{
    current_membership->sauna = frontdesk_station->sauna;
    current_membership->departments = true;
}

void FrontDeskStaff::include_pool_access()
{
    current_membership->swimming_pool = frontdesk_station->swimming_pool;
    current_membership->departments = true;
}

void FrontDeskStaff::include_ring_access()
{
    current_membership->wrestling_ring = frontdesk_station->wrestling_ring;
    current_membership->departments = true;
}

void FrontDeskStaff::configure_session_limit(int session_count)
{
    if (session_count < -1) {
        throw InvalidSessionCountError("Неверный аргумент");
    }
    current_membership->initial_num_of_sessions = session_count;
}

void FrontDeskStaff::configure_duration_days(unsigned int day_count)
{
    current_membership->validality_period = day_count;
}

void FrontDeskStaff::swap_membership_for_key()
{
    unsigned int slot = locate_available_key(current_membership->gender);
    key_storage->passkeys[slot].first.set_owner(current_membership->owner);
    key_to_distribute = &key_storage->passkeys[slot].first;
    key_storage->passkeys.erase(key_storage->passkeys.begin() + slot);
    key_storage->passkeys[slot].second = current_membership;
    key_to_distribute->owner = current_membership->owner;
    current_membership = nullptr;
}

unsigned int FrontDeskStaff::locate_available_key(const char gender_code) const
{
    for (unsigned int i = 0; i < key_storage->passkeys.size(); i++) {
        if (key_storage->passkeys[i].first.gender == gender_code &&
            !key_storage->passkeys[i].second) {
            return i;
        }
    }
    throw PasskeyValidationError("Нет ключей");
}

void FrontDeskStaff::distribute_key_to_client()
{
    if (key_to_distribute) {
        key_to_distribute->owner->access_card = key_to_distribute;
        key_to_distribute = nullptr;
    }
}

void FrontDeskStaff::collect_return_key(PersonBase& person)
{
    if (!key_to_return) {
        if (person.access_card) {
            key_to_return = person.access_card;
            person.access_card = nullptr;
        } else {
            throw PasskeyValidationError("У клиента нет ключа");
        }
    } else {
        throw PasskeyValidationError("Уже есть ключ который надо положить на место");
    }
}

void FrontDeskStaff::return_key_to_rack()
{
    unsigned int slot = locate_storage_slot();
    key_to_return = nullptr;
    current_membership = key_storage->passkeys[slot].second;
    key_storage->passkeys[slot].second = nullptr;
}

void FrontDeskStaff::return_membership_to_client()
{
    current_membership->owner->active_membership = current_membership;
    current_membership->owner->membership_active = false;
    current_membership = nullptr;
}

unsigned int FrontDeskStaff::locate_storage_slot()
{
    for (size_t i = 0; i < key_storage->passkeys.size(); i++) {
        if (&key_storage->passkeys[i].first == key_to_return) {
            return i;
        }
    }
    throw PasskeyValidationError("Не найдена нужная ячейка");
}

void FrontDeskStaff::decrement_day_count()
{
    client_database->change_remaining_days();
}

double FrontDeskStaff::retrieve_cash_register()
{
    return frontdesk_station->bank;
}
