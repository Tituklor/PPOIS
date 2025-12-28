#include "headband_defs.h"

Headband::Headband(double unit_price, ProductMaterial band_material,
                   ItemColor band_color, ProductSize band_size)
        : ProductBase(unit_price), band_material(band_material),
          band_color(band_color), band_size(band_size)
{
}
