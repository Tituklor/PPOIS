#ifndef CREATINE_SUPPLEMENT_H
#define CREATINE_SUPPLEMENT_H

#include "product_base.h"
#include <string>

class CreatineSupplement : public ProductBase
{
private:
    std::string manufacturer_brand;
    std::string item_name;
    std::string product_form;
    std::string creatine_variant;
    bool micronized_form;
    unsigned int portion_grams;
    unsigned int creatine_mg_per_portion;
    unsigned int total_portions;
    unsigned int packaging_weight_grams;
    std::string taste_profile;
    bool flavored_product;
    std::string origin_country;
    bool independently_verified;

public:
    CreatineSupplement(double unit_price, const std::string& manufacturer_brand,
                       const std::string& item_name, const std::string& product_form,
                       const std::string& creatine_variant, bool micronized_form,
                       unsigned int portion_grams, unsigned int creatine_mg_per_portion,
                       unsigned int total_portions, unsigned int packaging_weight_grams,
                       const std::string& taste_profile, bool flavored_product,
                       const std::string& origin_country, bool independently_verified);

    std::string retrieve_brand() const;
    std::string retrieve_item_name() const;
    std::string retrieve_form() const;
    std::string retrieve_variant() const;
    bool is_micronized_product() const;
    unsigned int retrieve_portion_size() const;
    unsigned int retrieve_creatine_content() const;
    unsigned int retrieve_total_portions() const;
    unsigned int retrieve_packaging_weight() const;
    std::string retrieve_taste() const;
    bool has_flavoring() const;
    std::string retrieve_origin() const;
    bool is_verified_product() const;
};

#endif
