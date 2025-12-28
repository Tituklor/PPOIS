#ifndef RING_ZONE_H
#define RING_ZONE_H

#include "zone_base.h"

class RingZone : public ZoneBase
{
    bool combat_bag_available;

public:
    RingZone(double area, double ring_size);
    RingZone(const double zone_price, const double zone_area, const bool combat_bag_available);
    bool has_combat_bag();
};

#endif
