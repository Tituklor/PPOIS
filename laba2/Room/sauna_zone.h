#ifndef SAUNA_ZONE_H
#define SAUNA_ZONE_H

#include "zone_base.h"

class SaunaZone : public ZoneBase
{
    unsigned int maximum_heat_level;
    unsigned int maximum_moisture_level;  // moisture in %

public:
    SaunaZone(const double zone_price, const double zone_area,
              const unsigned int maximum_heat_level, const unsigned int maximum_moisture_level);

    unsigned int retrieve_maximum_heat_level() const;
    unsigned int retrieve_maximum_moisture_level() const;
};

#endif
