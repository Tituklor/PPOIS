#ifndef EXERCISE_BALL_DEFS_H
#define EXERCISE_BALL_DEFS_H

#include <string>
#include "product_base.h"
#include "../Enums/enums_defs.h"

class ExerciseBall : public ProductBase
{
    BallCategory ball_category;
    std::string ball_size;
    ProductMaterial ball_material;
    double ball_mass_kg;

public:
    ExerciseBall(double item_price, BallCategory ball_category,
                 const std::string& ball_size,
                 ProductMaterial ball_material, double ball_mass_kg);

    BallCategory retrieve_category() const { return ball_category; }
    std::string retrieve_size() const { return ball_size; }
    ProductMaterial retrieve_material() const { return ball_material; }
    double retrieve_mass_kg() const { return ball_mass_kg; }

    std::string retrieve_category_name() const { return ValueConverter::convert(ball_category); }
    std::string retrieve_material_name() const { return ValueConverter::convert(ball_material); }
};

#endif
