// equipment/ResistanceBand.cpp
#include "ResistanceBand.h"
#include "../config/Config.h"

ResistanceBand::ResistanceBand(int quantity, const std::string& resistanceLevel)
        : Equipment("ResistanceBand", quantity, Config::EQUIPMENT_RENT_FEE, "good"),
          resistanceLevel_(resistanceLevel) {}

std::string ResistanceBand::getResistanceLevel() const {
    return resistanceLevel_;
}