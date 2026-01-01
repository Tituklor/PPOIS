// exceptions/FacilityBookedException.cpp
#include "FacilityBookedException.h"
#include <string>

FacilityBookedException::FacilityBookedException(
        const std::string& facilityName, const std::string& timeSlot)
        : BaseException("Facility '" + facilityName + "' already booked at " + timeSlot),
          facilityName_(facilityName), timeSlot_(timeSlot) {}

std::string FacilityBookedException::getFacilityName() const {
    return facilityName_;
}

std::string FacilityBookedException::getTimeSlot() const {
    return timeSlot_;
}