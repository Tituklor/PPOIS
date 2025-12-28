#include "gym_zone.h"

GymZone::GymZone(const double zone_price, const double zone_area, const bool pullup_bar_available,
                 const unsigned int trainer_station_count, const unsigned int weight_plate_count,
                 const unsigned int dumbbell_pair_count, const unsigned int barbell_count,
                 const unsigned int kettlebell_count, const unsigned int lifting_strap_count)
        : ZoneBase(zone_price, zone_area), pullup_bar_available(pullup_bar_available),
          trainer_station_count(trainer_station_count), weight_plate_count(weight_plate_count),
          dumbbell_pair_count(dumbbell_pair_count), barbell_count(barbell_count),
          kettlebell_count(kettlebell_count), lifting_strap_count(lifting_strap_count)
{
}

bool GymZone::has_pullup_bar() const
{
    return pullup_bar_available;
}

unsigned int GymZone::retrieve_trainer_station_count() const
{
    return trainer_station_count;
}

unsigned int GymZone::retrieve_weight_plate_count() const
{
    return weight_plate_count;
}

unsigned int GymZone::retrieve_dumbbell_pair_count() const
{
    return dumbbell_pair_count;
}

unsigned int GymZone::retrieve_barbell_count() const
{
    return barbell_count;
}

unsigned int GymZone::retrieve_kettlebell_count() const
{
    return kettlebell_count;
}

unsigned int GymZone::retrieve_lifting_strap_count() const
{
    return lifting_strap_count;
}
