#include "towel_defs.h"

Towel::Towel(double unit_price, TowelDimension towel_dimension,
             ProductMaterial towel_fabric, ItemColor towel_color,
             AbsorbLevel absorption_level)
        : ProductBase(unit_price), towel_dimension(towel_dimension),
          towel_fabric(towel_fabric), towel_color(towel_color),
          absorption_level(absorption_level)
{
}
