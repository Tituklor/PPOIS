#ifndef BEVERAGE_DEFS_H
#define BEVERAGE_DEFS_H

#include <string>
#include "product_base.h"

class Beverage : public ProductBase
{
    double container_volume;
    std::string beverage_name;
    bool sparkling_content;
    bool dairy_based;
    bool energy_formula;
    bool sugar_free;
    bool fruit_flavored;
    std::string flavor_profile;
    bool plastic_container;
    bool glass_container;
    bool metal_can;

public:
    Beverage(double unit_price, double container_volume, const std::string& beverage_name,
             bool sparkling_content, bool dairy_based, bool energy_formula, bool sugar_free,
             bool fruit_flavored, const std::string& flavor_profile,
             bool plastic_container, bool glass_container, bool metal_can);

    double retrieve_volume() const;
    std::string retrieve_name() const;
    bool is_sparkling() const;
    bool is_dairy() const;
    bool contains_energy() const;
    bool no_sugar_added() const;
    bool fruit_flavor() const;
    std::string retrieve_flavor() const;
    bool plastic_packaging() const;
    bool glass_packaging() const;
    bool metal_packaging() const;
};

#endif
