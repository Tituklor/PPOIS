#include "fitness_zone.h"

FitnessZone::FitnessZone(const double zone_price, const double zone_area,
                         const unsigned int mat_count, const unsigned int resistance_band_count,
                         const unsigned int hula_hoop_count, const unsigned int foam_roller_count,
                         const unsigned int exercise_ball_count, const unsigned int treadmill_count)
        : ZoneBase(zone_price, zone_area), mat_count(mat_count),
          resistance_band_count(resistance_band_count), hula_hoop_count(hula_hoop_count),
          foam_roller_count(foam_roller_count), exercise_ball_count(exercise_ball_count),
          treadmill_count(treadmill_count)
{
}

unsigned int FitnessZone::retrieve_mat_count() const
{
    return mat_count;
}

unsigned int FitnessZone::retrieve_resistance_band_count() const
{
    return resistance_band_count;
}

unsigned int FitnessZone::retrieve_hula_hoop_count() const
{
    return hula_hoop_count;
}

unsigned int FitnessZone::retrieve_foam_roller_count() const
{
    return foam_roller_count;
}

unsigned int FitnessZone::retrieve_exercise_ball_count() const
{
    return exercise_ball_count;
}

unsigned int FitnessZone::retrieve_treadmill_count() const
{
    return treadmill_count;
}
