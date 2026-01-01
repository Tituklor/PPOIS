// schedule/Booking.cpp
#include "Booking.h"
#include "../config/Config.h"

Booking::Booking(int personId, const std::string& facilityName,
                 const std::string& timeSlot, bool isMember)
        : personId_(personId), facilityName_(facilityName),
          timeSlot_(timeSlot), isMember_(isMember),
          status_(Config::STATUS_BOOKED) {}

int Booking::getPersonId() const {
    return personId_;
}

std::string Booking::getFacilityName() const {
    return facilityName_;
}

std::string Booking::getTimeSlot() const {
    return timeSlot_;
}

bool Booking::isForMember() const {
    return isMember_;
}

std::string Booking::getStatus() const {
    return status_;
}

void Booking::setStatus(const std::string& status) {
    status_ = status;
}