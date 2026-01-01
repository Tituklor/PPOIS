// equipment/ResistanceBand.h
#ifndef SPORTCLUB_RESISTANCEBAND_H
#define SPORTCLUB_RESISTANCEBAND_H

#include "Equipment.h"
#include <string>

class ResistanceBand : public Equipment {
public:
    ResistanceBand(int quantity, const std::string& resistanceLevel);
    std::string getResistanceLevel() const;

private:
    std::string resistanceLevel_; // "light", "medium", "heavy"
};

#endif // SPORTCLUB_RESISTANCEBAND_H