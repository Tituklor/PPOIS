#ifndef PROTEIN_BAR_DEFS_H
#define PROTEIN_BAR_DEFS_H

#include <string>
#include "product_base.h"

class ProteinBar : public ProductBase
{
private:
    std::string manufacturer;
    std::string bar_name;
    std::string taste_variant;
    double bar_weight_grams;
    double calorie_content;
    double protein_content_grams;
    double carbohydrate_content_grams;
    double sugar_content_grams;
    double fat_content_grams;
    double dietary_fiber_grams;
    bool vegan_certified;
    bool gluten_free;
    bool reduced_sugar;

public:
    ProteinBar(double unit_price, const std::string& manufacturer, const std::string& bar_name,
               const std::string& taste_variant, double bar_weight_grams, double calorie_content,
               double protein_content_grams, double carbohydrate_content_grams,
               double sugar_content_grams, double fat_content_grams, double dietary_fiber_grams,
               bool vegan_certified, bool gluten_free, bool reduced_sugar);

    std::string retrieve_manufacturer() const;
    std::string retrieve_bar_name() const;
    std::string retrieve_taste() const;
    double retrieve_weight() const;
    double retrieve_calories() const;
    double retrieve_protein() const;
    double retrieve_carbs() const;
    double retrieve_sugar() const;
    double retrieve_fat() const;
    double retrieve_fiber() const;
    bool is_vegan_product() const;
    bool is_gluten_free_product() const;
    bool is_low_sugar_product() const;
};

#endif
