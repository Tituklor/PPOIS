// schedule/Calendar.cpp
#include "Calendar.h"

void Calendar::addBooking(const Booking& booking) {
    bookings_.push_back(booking);
}

std::vector<Booking> Calendar::getBookingsByFacility(const std::string& facility) const {
    std::vector<Booking> result;
    for (const auto& b : bookings_) {
        if (b.getFacilityName() == facility) {
            result.push_back(b);
        }
    }
    return result;
}

std::vector<Booking> Calendar::getBookingsByTime(const std::string& timeSlot) const {
    std::vector<Booking> result;
    for (const auto& b : bookings_) {
        if (b.getTimeSlot() == timeSlot) {
            result.push_back(b);
        }
    }
    return result;
}

bool Calendar::isFacilityAvailable(const std::string& facility, const std::string& timeSlot) const {
    for (const auto& b : bookings_) {
        if (b.getFacilityName() == facility && b.getTimeSlot() == timeSlot) {
            return false;
        }
    }
    return true;
}

size_t Calendar::getBookingCount() const {
    return bookings_.size();
}