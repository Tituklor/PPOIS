// facility/Gym.h
#ifndef SPORTCLUB_GYM_H
#define SPORTCLUB_GYM_H

#include "Facility.h"

class Gym : public Facility {
public:
    Gym(const std::string& name, int capacity, const std::string& location);
    bool hasFreeWeights() const;
};

#endif // SPORTCLUB_GYM_H