#include "swimwear_defs.h"

Swimwear::Swimwear(double unit_price, ProductSize garment_size,
                   ProductMaterial fabric_material, ItemColor garment_color,
                   SwimStyle swim_style)
        : ProductBase(unit_price), garment_size(garment_size),
          fabric_material(fabric_material), garment_color(garment_color),
          swim_style(swim_style)
{
}
