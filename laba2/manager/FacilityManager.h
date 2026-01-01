// manager/FacilityManager.h
#ifndef SPORTCLUB_FACILITYMANAGER_H
#define SPORTCLUB_FACILITYMANAGER_H

#include "../facility/Facility.h"
#include <vector>

class FacilityManager {
public:
    void addFacility(const Facility& facility);
    Facility* findFacilityByName(const std::string& name);
    std::vector<Facility> getAllFacilities() const;
    size_t getFacilityCount() const;
    bool isFacilityAvailable(const std::string& name) const;

private:
    std::vector<Facility> facilities_;
};

#endif // SPORTCLUB_FACILITYMANAGER_H