#include "sauna_zone.h"
#include "../Human/error_defs.h"

SaunaZone::SaunaZone(const double zone_price, const double zone_area,
                     const unsigned int maximum_heat_level, const unsigned int maximum_moisture_level)
        : ZoneBase(zone_price, zone_area), maximum_heat_level(maximum_heat_level),
          maximum_moisture_level(maximum_moisture_level)
{
    if (maximum_moisture_level > 100)
        throw HumidityControlError("Влажность от 0 до 100%");
}

unsigned int SaunaZone::retrieve_maximum_heat_level() const
{
    return maximum_heat_level;
}

unsigned int SaunaZone::retrieve_maximum_moisture_level() const
{
    return maximum_moisture_level;
}
