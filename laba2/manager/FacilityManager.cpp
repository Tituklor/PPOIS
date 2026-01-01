// manager/FacilityManager.cpp
#include "FacilityManager.h"

void FacilityManager::addFacility(const Facility& facility) {
    facilities_.push_back(facility);
}

Facility* FacilityManager::findFacilityByName(const std::string& name) {
    for (auto& fac : facilities_) {
        if (fac.getName() == name) {
            return &fac;
        }
    }
    return nullptr;
}

std::vector<Facility> FacilityManager::getAllFacilities() const {
    return facilities_;
}

size_t FacilityManager::getFacilityCount() const {
    return facilities_.size();
}

bool FacilityManager::isFacilityAvailable(const std::string& name) const {
    for (const auto& fac : facilities_) {
        if (fac.getName() == name) {
            return fac.isAvailable();
        }
    }
    return false;
}