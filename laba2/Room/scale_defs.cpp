#include "scale_defs.h"
#include "../Human/error_defs.h"

WeightScale::WeightScale(const std::string& manufacturer, const std::string& device_model,
                         double maximum_load, double measurement_precision,
                         bool digital_display, bool backlight_feature,
                         bool auto_shutdown, bool battery_operation,
                         bool usb_power_support, double platform_dimensions)
        : manufacturer(manufacturer), device_model(device_model),
          maximum_load(maximum_load), measurement_precision(measurement_precision),
          digital_display(digital_display), backlight_feature(backlight_feature),
          auto_shutdown(auto_shutdown), battery_operation(battery_operation),
          usb_power_support(usb_power_support), platform_dimensions(platform_dimensions)
{
    if (!validate_measurement_precision())
        throw InvalidPrecisionError("Неверная точность");
}

bool WeightScale::validate_measurement_precision()
{
    double precision_log = std::log10(measurement_precision);
    return (precision_log - static_cast<int>(precision_log) == 0);
}

double WeightScale::measure_person_weight(PersonBase& person)
{
    return person.body_weight;
}
