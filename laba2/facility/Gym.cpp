// facility/Gym.cpp
#include "Gym.h"

Gym::Gym(const std::string& name, int capacity, const std::string& location)
        : Facility(name, "Gym", capacity, location) {}

bool Gym::hasFreeWeights() const {
    return true; // All gyms have free weights in this model
}