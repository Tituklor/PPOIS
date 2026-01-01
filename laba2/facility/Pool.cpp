// facility/Pool.cpp
#include "Pool.h"

Pool::Pool(const std::string& name, int capacity, const std::string& location,
           double depthMeters)
        : Facility(name, "Pool", capacity, location), depthMeters_(depthMeters) {}

double Pool::getDepth() const {
    return depthMeters_;
}

bool Pool::isHeated() const {
    return true; // All pools are heated
}