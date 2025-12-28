#include "frontdesk.h"  // ✅ Правильный путь!

// ✅ Инициализация в списке инициализации (лучшая практика)
FrontDesk::FrontDesk()
        : gym_area(nullptr)
        , fitness_area(nullptr)
        , sauna_area(nullptr)
        , pool_area(nullptr)
        , ring_area(nullptr)
        , cash_register(0.0)
{
}

void FrontDesk::register_fitness_zone(FitnessZone& fitness_zone) {
    fitness_area = &fitness_zone;
}

void FrontDesk::register_gym_zone(GymZone& gym_zone) {
    gym_area = &gym_zone;
}

void FrontDesk::register_sauna_zone(SaunaZone& sauna_zone) {
    sauna_area = &sauna_zone;
}

void FrontDesk::register_pool_zone(PoolZone& pool_zone) {
    pool_area = &pool_zone;
}

void FrontDesk::register_ring_zone(RingZone& ring_zone) {
    ring_area = &ring_zone;
}
