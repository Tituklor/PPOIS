#include "membership_defs.h"
#include "../Human/error_defs.h"

Membership::Membership(PersonBase& member)
        : days_remaining(0), sessions_remaining(0), original_session_limit(0),
          membership_duration(0), fitness_access(nullptr), gym_access(nullptr),
          sauna_access(nullptr), pool_access(nullptr), ring_access(nullptr)
{
    bind_member(member);
    multi_zone_access = false;
}

Membership::Membership(PersonBase& member, int original_session_limit, int membership_duration,
                       FitnessZone* fitness_access, GymZone* gym_access, SaunaZone* sauna_access,
                       PoolZone* pool_access, RingZone* ring_access)
        : original_session_limit(original_session_limit), membership_duration(membership_duration),
          days_remaining(membership_duration), sessions_remaining(original_session_limit),
          fitness_access(fitness_access), gym_access(gym_access), sauna_access(sauna_access),
          pool_access(pool_access), ring_access(ring_access)
{
    bind_member(member);
    validate_zone_access();
    if (!multi_zone_access)
        throw SubscriptionIssueError("Подписка без секций");
}

void Membership::bind_member(PersonBase& member)
{
    this->member = &member;
    member.active_membership = this;
    member_gender = member.sex_code;
}

char Membership::retrieve_member_gender()
{
    return member_gender;
}

void Membership::validate_zone_access()
{
    if (!gym_access || !sauna_access || !fitness_access || !pool_access || !ring_access)
    {
        multi_zone_access = true;
    } else {
        multi_zone_access = false;
    }
}

double Membership::calculate_cost()
{
    double total_cost = 0;
    if (multi_zone_access)
    {
        if (gym_access)
            total_cost += gym_access->price;
        if (fitness_access)
            total_cost += fitness_access->price;
        if (sauna_access)
            total_cost += sauna_access->price;
        if (pool_access)
            total_cost += pool_access->price;
        if (ring_access)
            total_cost += ring_access->price;
    }
    return total_cost * original_session_limit;
}

void Membership::expire_membership()
{
    days_remaining = 0;
    sessions_remaining = 0;
}
