#include "swim_cap_defs.h"

SwimCap::SwimCap(double unit_price, ProductMaterial cap_material,
                 ItemColor cap_color, ProductSize cap_size,
                 ResistanceLevel water_resist_level, StretchLevel stretch_level)
        : ProductBase(unit_price), cap_material(cap_material), cap_color(cap_color),
          cap_size(cap_size), water_resist_level(water_resist_level),
          stretch_level(stretch_level)
{
}
