#ifndef FRONTDESK_DEFS_H
#define FRONTDESK_DEFS_H

#include "employee_base.h"
#include "../Human/error_defs.h"

// ✅ Forward declarations - ИСПРАВЛЯЕТ C2061!
class KeyRack;
class PassKey;
class Membership;
class ClientRegistry;
class FrontDesk;
class PersonBase;
class Fitness;
class Gym;
class Sauna;
class SwimmingPool;
class WrestlingRing;

class FrontDeskStaff : public EmployeeBase
{
    friend class PersonBase;

private:
    KeyRack* key_storage;
    PassKey* key_to_distribute;
    PassKey* key_to_return;
    Membership* current_membership;
    ClientRegistry* client_database;
    FrontDesk* frontdesk_station;

    void clear_membership();
    void clear_membership(PersonBase& person);

public:
    FrontDeskStaff(std::string staff_name, unsigned int staff_age, char staff_gender,
                   std::string staff_birth, bool key_link_perm, PassKey* staff_key,
                   bool staff_has_sub, double staff_balance, double staff_weight,
                   unsigned int staff_height, unsigned int staff_exp, double staff_salary,
                   std::string staff_phone, KeyRack* key_storage, ClientRegistry* client_database,
                   FrontDesk* frontdesk_station);

    double retrieve_cash_register();

    void retrieve_key_from_rack();
    bool validate_sessions_and_duration();
    void collect_client_membership(PersonBase& person);
    void generate_client_membership(PersonBase& person);
    void generate_client_membership(PersonBase& person, int session_limit, int duration_days,
                                    Fitness* fitness_area, Gym* gym_area, Sauna* sauna_area,
                                    SwimmingPool* pool_area, WrestlingRing* ring_area);
    void register_client(PersonBase& person);

    void include_gym_access();
    void include_fitness_access();
    void include_sauna_access();
    void include_pool_access();
    void include_ring_access();

    void process_payment_for_membership();
    void configure_session_limit(int session_count);
    void configure_duration_days(unsigned int day_count);
    void decrement_session_count();
    unsigned int locate_available_key(char gender_code) const;
    bool verify_client_membership(PersonBase& person);
    void swap_membership_for_key();
    void distribute_key_to_client();
    void collect_return_key(PersonBase& person);
    void return_key_to_rack();
    void return_membership_to_client();
    unsigned int locate_storage_slot();
    void decrement_day_count();
};

#endif // FRONTDESK_DEFS_H
