#ifndef ZONE_BASE_H
#define ZONE_BASE_H

#include "space_defs.h"

class ZoneBase : public Space
{
protected:
    friend class Membership;

    double zone_price;

public:
    ZoneBase(const double zone_price, const double zone_area);
};

#endif
