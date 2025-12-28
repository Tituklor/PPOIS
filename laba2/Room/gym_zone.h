#ifndef GYM_ZONE_H
#define GYM_ZONE_H

#include "zone_base.h"

class GymZone : public ZoneBase
{
    bool pullup_bar_available;
    unsigned int trainer_station_count;
    unsigned int weight_plate_count;
    unsigned int dumbbell_pair_count;
    unsigned int barbell_count;
    unsigned int kettlebell_count;
    unsigned int lifting_strap_count;

public:
    GymZone(const double zone_price, const double zone_area, const bool pullup_bar_available,
            const unsigned int trainer_station_count, const unsigned int weight_plate_count,
            const unsigned int dumbbell_pair_count, const unsigned int barbell_count,
            const unsigned int kettlebell_count, const unsigned int lifting_strap_count);

    bool has_pullup_bar() const;
    unsigned int retrieve_trainer_station_count() const;
    unsigned int retrieve_weight_plate_count() const;
    unsigned int retrieve_dumbbell_pair_count() const;
    unsigned int retrieve_barbell_count() const;
    unsigned int retrieve_kettlebell_count() const;
    unsigned int retrieve_lifting_strap_count() const;
};

#endif
