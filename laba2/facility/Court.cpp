// facility/Court.cpp
#include "Court.h"

Court::Court(const std::string& name, int capacity, const std::string& location,
             const std::string& sportType)
        : Facility(name, "Court", capacity, location), sportType_(sportType) {}

std::string Court::getSportType() const {
    return sportType_;
}