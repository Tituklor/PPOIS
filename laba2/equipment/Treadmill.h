// equipment/Treadmill.h
#ifndef SPORTCLUB_TREADMILL_H
#define SPORTCLUB_TREADMILL_H

#include "Equipment.h"

class Treadmill : public Equipment {
public:
    Treadmill(int quantity, double maxSpeedKmh);
    double getMaxSpeed() const;
    bool hasIncline() const;

private:
    double maxSpeedKmh_;
};

#endif // SPORTCLUB_TREADMILL_H