#ifndef FRONTDESK_H
#define FRONTDESK_H

#include <vector>
#include "../Room/storage_defs.h"
#include "../Human/frontdesk_defs.h"
#include "../Room/gym_zone.h"
#include "../Room/fitness_zone.h"
#include "../Room/sauna_zone.h"
#include "../Room/pool_zone.h"
#include "../Room/ring_zone.h"

class FitnessZone;
class GymZone;
class SaunaZone;
class PoolZone;
class RingZone;

class FrontDesk
{

    friend class FrontDeskStaff;

    FitnessZone* fitness_area;
    GymZone* gym_area;
    SaunaZone* sauna_area;
    PoolZone* pool_area;
    RingZone* ring_area;
    double cash_register;

private:
    GymZone* gym_area;
    FitnessZone* fitness_area;
    SaunaZone* sauna_area;
    PoolZone* pool_area;
    RingZone* ring_area;
    double cash_register;

public:
    FrontDesk();
    void register_gym_zone(GymZone& gym_zone);
    void register_sauna_zone(SaunaZone& sauna_zone);
    void register_fitness_zone(FitnessZone& fitness_zone);
    void register_pool_zone(PoolZone& pool_zone);
    void register_ring_zone(RingZone& ring_zone);
};

#endif
