#include "beverage_defs.h"
#include "../Human/error_defs.h"
Beverage::Beverage(double unit_price, double container_volume, const std::string& beverage_name,
                   bool sparkling_content, bool dairy_based, bool energy_formula, bool sugar_free,
                   bool fruit_flavored, const std::string& flavor_profile,
                   bool plastic_container, bool glass_container, bool metal_can)
        : ProductBase(unit_price), container_volume(container_volume), beverage_name(beverage_name),
          sparkling_content(sparkling_content), dairy_based(dairy_based),
          energy_formula(energy_formula), sugar_free(sugar_free), fruit_flavored(fruit_flavored),
          flavor_profile(flavor_profile), plastic_container(plastic_container),
          glass_container(glass_container), metal_can(metal_can)
{
    if ((plastic_container && glass_container) || (plastic_container && metal_can) ||
        (glass_container && metal_can))
        throw InvalidPackagingError("Либо пластик, либо стекло, либо банка");
    else if (!plastic_container && !glass_container && !metal_can)
        throw InvalidPackagingError("Либо пластик, либо стекло, либо банка");

    if (container_volume < 0 || container_volume > 5)
        throw InvalidVolumeError("Неверный объем (от 0 до 5 л)");
}

double Beverage::retrieve_volume() const { return container_volume; }
std::string Beverage::retrieve_name() const { return beverage_name; }
bool Beverage::is_sparkling() const { return sparkling_content; }
bool Beverage::is_dairy() const { return dairy_based; }
bool Beverage::contains_energy() const { return energy_formula; }
bool Beverage::no_sugar_added() const { return sugar_free; }
bool Beverage::fruit_flavor() const { return fruit_flavored; }
std::string Beverage::retrieve_flavor() const { return flavor_profile; }
bool Beverage::plastic_packaging() const { return plastic_container; }
bool Beverage::glass_packaging() const { return glass_container; }
bool Beverage::metal_packaging() const { return metal_can; }
