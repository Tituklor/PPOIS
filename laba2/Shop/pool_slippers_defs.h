#ifndef POOL_SLIPPERS_DEFS_H
#define POOL_SLIPPERS_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class PoolSlippers : public ProductBase
{
    ProductSize footwear_size;
    ItemColor footwear_color;
    ProductMaterial footwear_material;
    std::string manufacturer_brand;

public:
    PoolSlippers(double unit_price, ProductSize footwear_size, ItemColor footwear_color,
                 ProductMaterial footwear_material, std::string manufacturer_brand);

    ProductSize retrieve_size() const { return footwear_size; }
    ItemColor retrieve_color() const { return footwear_color; }
    ProductMaterial retrieve_material() const { return footwear_material; }
    std::string retrieve_brand() const { return manufacturer_brand; }

    std::string retrieve_size_name() const { return ValueConverter::convert(footwear_size); }
    std::string retrieve_color_name() const { return ValueConverter::convert(footwear_color); }
    std::string retrieve_material_name() const { return ValueConverter::convert(footwear_material); }
};

#endif
