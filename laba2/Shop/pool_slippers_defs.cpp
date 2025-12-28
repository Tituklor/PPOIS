#include "pool_slippers_defs.h"

PoolSlippers::PoolSlippers(double unit_price, ProductSize footwear_size,
                           ItemColor footwear_color, ProductMaterial footwear_material,
                           std::string manufacturer_brand)
        : ProductBase(unit_price), footwear_size(footwear_size), footwear_color(footwear_color),
          footwear_material(footwear_material), manufacturer_brand(manufacturer_brand)
{
}
