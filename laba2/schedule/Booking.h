// schedule/Booking.h
#ifndef SPORTCLUB_BOOKING_H
#define SPORTCLUB_BOOKING_H

#include <string>

class Booking {
public:
    Booking(int personId, const std::string& facilityName,
            const std::string& timeSlot, bool isMember);

    int getPersonId() const;
    std::string getFacilityName() const;
    std::string getTimeSlot() const;
    bool isForMember() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);

private:
    int personId_;
    std::string facilityName_;
    std::string timeSlot_;
    bool isMember_;
    std::string status_;
};

#endif // SPORTCLUB_BOOKING_H