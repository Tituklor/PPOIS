// equipment/DumbbellSet.cpp
#include "DumbbellSet.h"
#include "../config/Config.h"

DumbbellSet::DumbbellSet(int quantity, double minWeightKg, double maxWeightKg)
        : Equipment("DumbbellSet", quantity, Config::EQUIPMENT_RENT_FEE, "good"),
          minWeightKg_(minWeightKg), maxWeightKg_(maxWeightKg) {}

double DumbbellSet::getMinWeight() const {
    return minWeightKg_;
}

double DumbbellSet::getMaxWeight() const {
    return maxWeightKg_;
}