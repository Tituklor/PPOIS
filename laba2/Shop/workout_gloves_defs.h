#ifndef WORKOUT_GLOVES_DEFS_H
#define WORKOUT_GLOVES_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class WorkoutGloves : public ProductBase
{
    ProductSize glove_size;
    ProductMaterial glove_material;
    bool wrist_stabilizer;

public:
    WorkoutGloves(double unit_price, ProductSize glove_size,
                  ProductMaterial glove_material, bool wrist_stabilizer);

    ProductSize retrieve_size() const { return glove_size; }
    ProductMaterial retrieve_material() const { return glove_material; }
    bool has_wrist_support() const { return wrist_stabilizer; }

    std::string retrieve_size_name() const { return ValueConverter::convert(glove_size); }
    std::string retrieve_material_name() const { return ValueConverter::convert(glove_material); }
};

#endif
