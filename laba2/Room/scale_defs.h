#ifndef SCALE_DEFS_H
#define SCALE_DEFS_H

#include <string>
#include <cmath>
#include "../Human/person_base.h"

class WeightScale
{
private:
    std::string manufacturer;
    std::string device_model;
    double maximum_load;
    double measurement_precision;
    bool digital_display;
    bool backlight_feature;
    bool auto_shutdown;
    bool battery_operation;
    bool usb_power_support;
    double platform_dimensions;
    bool validate_measurement_precision();

public:
    WeightScale(const std::string& manufacturer, const std::string& device_model,
                double maximum_load, double measurement_precision,
                bool digital_display, bool backlight_feature,
                bool auto_shutdown, bool battery_operation,
                bool usb_power_support, double platform_dimensions);

    double measure_person_weight(PersonBase& person);
};

#endif
