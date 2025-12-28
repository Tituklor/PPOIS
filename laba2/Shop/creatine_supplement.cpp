#include "creatine_supplement.h"

CreatineSupplement::CreatineSupplement(double unit_price, const std::string& manufacturer_brand,
                                       const std::string& item_name, const std::string& product_form,
                                       const std::string& creatine_variant, bool micronized_form,
                                       unsigned int portion_grams, unsigned int creatine_mg_per_portion,
                                       unsigned int total_portions, unsigned int packaging_weight_grams,
                                       const std::string& taste_profile, bool flavored_product,
                                       const std::string& origin_country, bool independently_verified)
        : ProductBase(unit_price), manufacturer_brand(manufacturer_brand), item_name(item_name),
          product_form(product_form), creatine_variant(creatine_variant),
          micronized_form(micronized_form), portion_grams(portion_grams),
          creatine_mg_per_portion(creatine_mg_per_portion), total_portions(total_portions),
          packaging_weight_grams(packaging_weight_grams), taste_profile(taste_profile),
          flavored_product(flavored_product), origin_country(origin_country),
          independently_verified(independently_verified)
{
}

std::string CreatineSupplement::retrieve_brand() const { return manufacturer_brand; }
std::string CreatineSupplement::retrieve_item_name() const { return item_name; }
std::string CreatineSupplement::retrieve_form() const { return product_form; }
std::string CreatineSupplement::retrieve_variant() const { return creatine_variant; }
bool CreatineSupplement::is_micronized_product() const { return micronized_form; }
unsigned int CreatineSupplement::retrieve_portion_size() const { return portion_grams; }
unsigned int CreatineSupplement::retrieve_creatine_content() const { return creatine_mg_per_portion; }
unsigned int CreatineSupplement::retrieve_total_portions() const { return total_portions; }
unsigned int CreatineSupplement::retrieve_packaging_weight() const { return packaging_weight_grams; }
std::string CreatineSupplement::retrieve_taste() const { return taste_profile; }
bool CreatineSupplement::has_flavoring() const { return flavored_product; }
std::string CreatineSupplement::retrieve_origin() const { return origin_country; }
bool CreatineSupplement::is_verified_product() const { return independently_verified; }
