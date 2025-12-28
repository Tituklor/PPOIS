#include "workout_gloves_defs.h"

WorkoutGloves::WorkoutGloves(double unit_price, ProductSize glove_size,
                             ProductMaterial glove_material, bool wrist_stabilizer)
        : ProductBase(unit_price), glove_size(glove_size),
          glove_material(glove_material), wrist_stabilizer(wrist_stabilizer)
{
}
