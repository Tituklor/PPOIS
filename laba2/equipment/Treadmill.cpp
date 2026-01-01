// equipment/Treadmill.cpp
#include "Treadmill.h"
#include "../config/Config.h"

Treadmill::Treadmill(int quantity, double maxSpeedKmh)
        : Equipment("Treadmill", quantity, Config::EQUIPMENT_RENT_FEE, "good"),
          maxSpeedKmh_(maxSpeedKmh) {}

double Treadmill::getMaxSpeed() const {
    return maxSpeedKmh_;
}

bool Treadmill::hasIncline() const {
    return true;
}