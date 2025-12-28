#ifndef FITNESS_ZONE_H
#define FITNESS_ZONE_H

#include "zone_base.h"

class FitnessZone : public ZoneBase
{
    unsigned int mat_count;
    unsigned int resistance_band_count;
    unsigned int hula_hoop_count;
    unsigned int foam_roller_count;
    unsigned int exercise_ball_count;
    unsigned int treadmill_count;

public:
    FitnessZone(const double zone_price, const double zone_area,
                const unsigned int mat_count, const unsigned int resistance_band_count,
                const unsigned int hula_hoop_count, const unsigned int foam_roller_count,
                const unsigned int exercise_ball_count, const unsigned int treadmill_count);

    unsigned int retrieve_mat_count() const;
    unsigned int retrieve_resistance_band_count() const;
    unsigned int retrieve_hula_hoop_count() const;
    unsigned int retrieve_foam_roller_count() const;
    unsigned int retrieve_exercise_ball_count() const;
    unsigned int retrieve_treadmill_count() const;
};

#endif
