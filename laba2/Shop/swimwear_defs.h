#ifndef SWIMWEAR_DEFS_H
#define SWIMWEAR_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class Swimwear : public ProductBase
{
    ProductSize garment_size;
    ProductMaterial fabric_material;
    ItemColor garment_color;
    SwimStyle swim_style;

public:
    Swimwear(double unit_price, ProductSize garment_size,
             ProductMaterial fabric_material, ItemColor garment_color,
             SwimStyle swim_style);

    ProductSize retrieve_size() const { return garment_size; }
    ProductMaterial retrieve_material() const { return fabric_material; }
    ItemColor retrieve_color() const { return garment_color; }
    SwimStyle retrieve_style() const { return swim_style; }

    std::string retrieve_size_name() const { return ValueConverter::convert(garment_size); }
    std::string retrieve_material_name() const { return ValueConverter::convert(fabric_material); }
    std::string retrieve_color_name() const { return ValueConverter::convert(garment_color); }
    std::string retrieve_style_name() const { return ValueConverter::convert(swim_style); }
};

#endif
