// schedule/Calendar.h
#ifndef SPORTCLUB_CALENDAR_H
#define SPORTCLUB_CALENDAR_H

#include "Booking.h"
#include <vector>
#include <string>

class Calendar {
public:
    void addBooking(const Booking& booking);
    std::vector<Booking> getBookingsByFacility(const std::string& facility) const;
    std::vector<Booking> getBookingsByTime(const std::string& timeSlot) const;
    bool isFacilityAvailable(const std::string& facility, const std::string& timeSlot) const;
    size_t getBookingCount() const;

private:
    std::vector<Booking> bookings_;
};

#endif // SPORTCLUB_CALENDAR_H