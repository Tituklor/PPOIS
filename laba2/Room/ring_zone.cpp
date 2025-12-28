#include "../Room/zone_base.h"
#include "../Human/client_defs.h"
RingZone::RingZone(double zone_price, double zone_area)
        : ZoneBase(zone_price, zone_area)
{
}

bool RingZone::has_combat_bag()
{
    return combat_bag_available;
}
