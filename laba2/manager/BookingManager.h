// manager/BookingManager.h
#ifndef SPORTCLUB_BOOKINGMANAGER_H
#define SPORTCLUB_BOOKINGMANAGER_H

#include "../schedule/Booking.h"
#include "../schedule/Calendar.h"
#include <vector>

class BookingManager {
public:
    void addBooking(const Booking& booking);
    std::vector<Booking> getBookingsByPerson(int personId) const;
    std::vector<Booking> getBookingsByFacility(const std::string& facility) const;
    bool isTimeSlotAvailable(const std::string& facility, const std::string& timeSlot) const;
    size_t getBookingCount() const;

private:
    Calendar calendar_;
};

#endif // SPORTCLUB_BOOKINGMANAGER_H