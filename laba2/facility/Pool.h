// facility/Pool.h
#ifndef SPORTCLUB_POOL_H
#define SPORTCLUB_POOL_H

#include "Facility.h"

class Pool : public Facility {
public:
    Pool(const std::string& name, int capacity, const std::string& location,
         double depthMeters);
    double getDepth() const;
    bool isHeated() const;

private:
    double depthMeters_;
};

#endif // SPORTCLUB_POOL_H