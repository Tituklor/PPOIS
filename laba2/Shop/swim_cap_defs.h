#ifndef SWIM_CAP_DEFS_H
#define SWIM_CAP_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class SwimCap : public ProductBase
{
    ProductMaterial cap_material;
    ItemColor cap_color;
    ProductSize cap_size;
    ResistanceLevel water_resist_level;
    StretchLevel stretch_level;

public:
    SwimCap(double unit_price, ProductMaterial cap_material, ItemColor cap_color,
            ProductSize cap_size, ResistanceLevel water_resist_level,
            StretchLevel stretch_level);

    ProductMaterial retrieve_material() const { return cap_material; }
    ItemColor retrieve_color() const { return cap_color; }
    ProductSize retrieve_size() const { return cap_size; }
    ResistanceLevel retrieve_water_resistance() const { return water_resist_level; }
    StretchLevel retrieve_elasticity() const { return stretch_level; }

    std::string retrieve_material_name() const { return ValueConverter::convert(cap_material); }
    std::string retrieve_color_name() const { return ValueConverter::convert(cap_color); }
    std::string retrieve_size_name() const { return ValueConverter::convert(cap_size); }
    std::string retrieve_resistance_name() const { return ValueConverter::convert(water_resist_level); }
    std::string retrieve_stretch_name() const { return ValueConverter::convert(stretch_level); }
};

#endif
