#ifndef MEMBERSHIP_DEFS_H
#define MEMBERSHIP_DEFS_H

#include <vector>
#include <string>

// ✅ Forward declarations ПЕРЕД include
class PersonBase;
class FitnessZone;
class GymZone;
class SaunaZone;
class PoolZone;
class RingZone;

// ✅ Include ПОСЛЕ forward declarations
#include "../Human/person_base.h"
#include "../Room/fitness_zone.h"
#include "../Room/gym_zone.h"
#include "../Room/sauna_zone.h"
#include "../Room/pool_zone.h"
#include "../Room/ring_zone.h"

class Membership
{
private:
    std::string membership_type;
    unsigned int remaining_sessions;
    bool is_active;
    double monthly_fee;
    unsigned int remaining_days;
    unsigned int validity_period;        // ✅ validity (не validality)
    unsigned int initial_num_of_sessions;

    // ✅ ПОЛЯ ДЛЯ frontdesk_defs.cpp
    double price;                        // ✅ price
    PersonBase* owner;                   // ✅ owner
    GymZone* gym;                        // ✅ gym
    FitnessZone* fitness;                // ✅ fitness
    SaunaZone* sauna;                    // ✅ sauna
    PoolZone* swimming_pool;             // ✅ swimming_pool
    RingZone* wrestling_ring;            // ✅ wrestling_ring
    std::string departments;             // ✅ departments
    char gender;                         // ✅ gender

protected:
    FitnessZone* fitness_access;
    GymZone* gym_access;
    SaunaZone* sauna_access;
    PoolZone* pool_access;
    RingZone* ring_access;
    unsigned int membership_duration;
    unsigned int days_remaining;
    int original_session_limit;
    int sessions_remaining;
    PersonBase* member;
    char member_gender;
    bool multi_zone_access;

    void validate_zone_access();

public:
    // ✅ Конструкторы
    Membership(PersonBase& member);
    Membership(PersonBase& member, int original_session_limit, int membership_duration,
               FitnessZone* fitness_access, GymZone* gym_access, SaunaZone* sauna_access,
               PoolZone* pool_access, RingZone* ring_access);

    // ✅ ГЕТТЕРЫ ДЛЯ frontdesk_defs.cpp
    double get_price() const { return price; }
    PersonBase* get_owner() const { return owner; }
    char get_gender() const { return gender; }
    std::string get_departments() const { return departments; }
    GymZone* get_gym() const { return gym; }
    FitnessZone* get_fitness() const { return fitness; }
    SaunaZone* get_sauna() const { return sauna; }
    PoolZone* get_swimming_pool() const { return swimming_pool; }
    RingZone* get_wrestling_ring() const { return wrestling_ring; }

    // ✅ Методы
    void bind_member(PersonBase& member);
    char retrieve_member_gender();
    double calculate_cost();
    void expire_membership();
    void make_empty();

    friend class PersonBase;
    friend class FrontDeskStaff;
    friend class ClientRegistry;
};

#endif // MEMBERSHIP_DEFS_H
