#ifndef POOL_ZONE_H
#define POOL_ZONE_H

#include "zone_base.h"

class PoolZone : public ZoneBase
{
private:
    double water_depth;
    double pool_length;
    unsigned int swimming_lanes_count;
    double diving_platform_height;

public:
    // ✅ ДОБАВИТЬ ЭТОТ КОНСТРУКТОР для pool_zone.cpp
    PoolZone(double area, double depth);

    // Основной конструктор
    PoolZone(const double zone_price, const double zone_area,
             const double water_depth, const double pool_length,
             const unsigned int swimming_lanes_count,
             const double diving_platform_height);

    double retrieve_water_depth() const;
    double retrieve_pool_length() const;
    unsigned int retrieve_swimming_lanes_count() const;
    double retrieve_diving_platform_height() const;
};

#endif // POOL_ZONE_H
