#include "jump_rope_defs.h"

JumpRope::JumpRope(double unit_price, const std::string& rope_length,
                   ProductMaterial rope_material, GripType handle_grip)
        : ProductBase(unit_price), rope_length(rope_length),
          rope_material(rope_material), handle_grip(handle_grip)
{
}
