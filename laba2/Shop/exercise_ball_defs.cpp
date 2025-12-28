#include "exercise_ball_defs.h"

ExerciseBall::ExerciseBall(double item_price, BallCategory ball_category,
                           const std::string& ball_size,
                           ProductMaterial ball_material, double ball_mass_kg)
        : ProductBase(item_price), ball_category(ball_category), ball_size(ball_size),
          ball_material(ball_material), ball_mass_kg(ball_mass_kg)
{
}
