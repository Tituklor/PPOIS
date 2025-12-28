#include "pool_zone.h"  // ✅ Правильный путь!

PoolZone::PoolZone(double zone_area, double water_depth)
        : ZoneBase(0.0, zone_area),  // ✅ Правильная инициализация ZoneBase
          water_depth(water_depth),  // ✅ Инициализация полей
          pool_length(25.0),
          swimming_lanes_count(8),
          diving_platform_height(3.0)
{
}

double PoolZone::retrieve_water_depth() const {
    return water_depth;
}

double PoolZone::retrieve_pool_length() const {
    return pool_length;
}

unsigned int PoolZone::retrieve_swimming_lanes_count() const {
    return swimming_lanes_count;
}

double PoolZone::retrieve_diving_platform_height() const {
    return diving_platform_height;
}
