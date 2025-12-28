#ifndef HEADBAND_DEFS_H
#define HEADBAND_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class Headband : public ProductBase
{
    ProductMaterial band_material;
    ItemColor band_color;
    ProductSize band_size;

public:
    Headband(double unit_price, ProductMaterial band_material,
             ItemColor band_color, ProductSize band_size);

    ProductMaterial retrieve_material() const { return band_material; }
    ItemColor retrieve_color() const { return band_color; }
    ProductSize retrieve_size() const { return band_size; }

    std::string retrieve_material_name() const { return ValueConverter::convert(band_material); }
    std::string retrieve_color_name() const { return ValueConverter::convert(band_color); }
    std::string retrieve_size_name() const { return ValueConverter::convert(band_size); }
};

#endif
