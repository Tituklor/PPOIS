#ifndef JUMP_ROPE_DEFS_H
#define JUMP_ROPE_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class JumpRope : public ProductBase
{
    std::string rope_length;
    ProductMaterial rope_material;
    GripType handle_grip;

public:
    JumpRope(double unit_price, const std::string& rope_length,
             ProductMaterial rope_material, GripType handle_grip);

    std::string retrieve_length() const { return rope_length; }
    ProductMaterial retrieve_material() const { return rope_material; }
    GripType retrieve_handle_type() const { return handle_grip; }

    std::string retrieve_material_name() const { return ValueConverter::convert(rope_material); }
    std::string retrieve_handle_name() const { return ValueConverter::convert(handle_grip); }
};

#endif
