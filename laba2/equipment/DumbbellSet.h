// equipment/DumbbellSet.h
#ifndef SPORTCLUB_DUMBBELLSET_H
#define SPORTCLUB_DUMBBELLSET_H

#include "Equipment.h"

class DumbbellSet : public Equipment {
public:
    DumbbellSet(int quantity, double minWeightKg, double maxWeightKg);
    double getMinWeight() const;
    double getMaxWeight() const;

private:
    double minWeightKg_;
    double maxWeightKg_;
};

#endif // SPORTCLUB_DUMBBELLSET_H