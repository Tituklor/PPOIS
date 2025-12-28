#include "zone_base.h"

ZoneBase::ZoneBase(const double zone_price, const double zone_area)
        : Space(zone_area), zone_price(zone_price)
{
}
