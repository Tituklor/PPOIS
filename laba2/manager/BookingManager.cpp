// manager/BookingManager.cpp
#include "BookingManager.h"
#include "../exceptions/FacilityBookedException.h"

void BookingManager::addBooking(const Booking& booking) {
    if (!isTimeSlotAvailable(booking.getFacilityName(), booking.getTimeSlot())) {
        throw FacilityBookedException(booking.getFacilityName(), booking.getTimeSlot());
    }
    calendar_.addBooking(booking);
}

std::vector<Booking> BookingManager::getBookingsByPerson(int personId) const {
    std::vector<Booking> result;
    for (const auto& b : calendar_.getBookingsByTime("")) { // get all
        if (b.getPersonId() == personId) {
            result.push_back(b);
        }
    }
    return result;
}

std::vector<Booking> BookingManager::getBookingsByFacility(const std::string& facility) const {
    return calendar_.getBookingsByFacility(facility);
}

bool BookingManager::isTimeSlotAvailable(const std::string& facility, const std::string& timeSlot) const {
    return calendar_.isFacilityAvailable(facility, timeSlot);
}

size_t BookingManager::getBookingCount() const {
    return calendar_.getBookingCount();
}