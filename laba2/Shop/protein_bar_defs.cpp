#include "protein_bar_defs.h"

ProteinBar::ProteinBar(double unit_price, const std::string& manufacturer,
                       const std::string& bar_name, const std::string& taste_variant,
                       double bar_weight_grams, double calorie_content,
                       double protein_content_grams, double carbohydrate_content_grams,
                       double sugar_content_grams, double fat_content_grams,
                       double dietary_fiber_grams, bool vegan_certified,
                       bool gluten_free, bool reduced_sugar)
        : ProductBase(unit_price), manufacturer(manufacturer), bar_name(bar_name),
          taste_variant(taste_variant), bar_weight_grams(bar_weight_grams),
          calorie_content(calorie_content), protein_content_grams(protein_content_grams),
          carbohydrate_content_grams(carbohydrate_content_grams),
          sugar_content_grams(sugar_content_grams), fat_content_grams(fat_content_grams),
          dietary_fiber_grams(dietary_fiber_grams), vegan_certified(vegan_certified),
          gluten_free(gluten_free), reduced_sugar(reduced_sugar)
{
}

std::string ProteinBar::retrieve_manufacturer() const { return manufacturer; }
std::string ProteinBar::retrieve_bar_name() const { return bar_name; }
std::string ProteinBar::retrieve_taste() const { return taste_variant; }
double ProteinBar::retrieve_weight() const { return bar_weight_grams; }
double ProteinBar::retrieve_calories() const { return calorie_content; }
double ProteinBar::retrieve_protein() const { return protein_content_grams; }
double ProteinBar::retrieve_carbs() const { return carbohydrate_content_grams; }
double ProteinBar::retrieve_sugar() const { return sugar_content_grams; }
double ProteinBar::retrieve_fat() const { return fat_content_grams; }
double ProteinBar::retrieve_fiber() const { return dietary_fiber_grams; }
bool ProteinBar::is_vegan_product() const { return vegan_certified; }
bool ProteinBar::is_gluten_free_product() const { return gluten_free; }
bool ProteinBar::is_low_sugar_product() const { return reduced_sugar; }
