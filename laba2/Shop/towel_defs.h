#ifndef TOWEL_DEFS_H
#define TOWEL_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class Towel : public ProductBase
{
    TowelDimension towel_dimension;
    ProductMaterial towel_fabric;
    ItemColor towel_color;
    AbsorbLevel absorption_level;

public:
    Towel(double unit_price, TowelDimension towel_dimension,
          ProductMaterial towel_fabric, ItemColor towel_color,
          AbsorbLevel absorption_level = AbsorbLevel::AbsorbMedium);

    TowelDimension retrieve_dimension() const { return towel_dimension; }
    ProductMaterial retrieve_fabric() const { return towel_fabric; }
    ItemColor retrieve_color() const { return towel_color; }
    AbsorbLevel retrieve_absorption() const { return absorption_level; }

    std::string retrieve_dimension_name() const { return ValueConverter::convert(towel_dimension); }
    std::string retrieve_fabric_name() const { return ValueConverter::convert(towel_fabric); }
    std::string retrieve_color_name() const { return ValueConverter::convert(towel_color); }
    std::string retrieve_absorption_name() const { return ValueConverter::convert(absorption_level); }
};

#endif
