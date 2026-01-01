// server/ClubServer.h
#ifndef SPORTCLUB_CLUBSERVER_H
#define SPORTCLUB_CLUBSERVER_H

#include "../manager/MemberManager.h"
#include "../manager/CoachManager.h"
#include "../manager/FacilityManager.h"
#include "../manager/EquipmentManager.h"
#include "../manager/PaymentManager.h"
#include "../manager/BookingManager.h"

class ClubServer {
public:
    ClubServer();

    // Core operations
    bool registerMember(const std::string& name, int age,
                        const std::string& phone, const std::string& email);
    bool hireCoach(const std::string& name, int age,
                   const std::string& phone, const std::string& email,
                   const std::string& specialization);
    bool addFacility(const std::string& name, const std::string& type,
                     int capacity, const std::string& location);
    bool bookSession(int personId, const std::string& facility,
                     const std::string& timeSlot, bool isMember);
    bool processPayment(int memberId, double amount, const std::string& desc);
    bool rentEquipment(const std::string& type, int quantity);
    bool assignLocker(int memberId, int lockerNumber);

    // Queries
    Member* getMember(int id);
    Coach* getCoach(int id);
    Facility* getFacility(const std::string& name);
    double getRevenue() const;
    size_t getTotalMembers() const;

private:
    MemberManager memberManager_;
    CoachManager coachManager_;
    FacilityManager facilityManager_;
    EquipmentManager equipmentManager_;
    PaymentManager paymentManager_;
    BookingManager bookingManager_;
    int nextMemberId_ = 1001;
    int nextCoachId_ = 2001;
    int nextLockerNumber_ = 1;
};

#endif // SPORTCLUB_CLUBSERVER_H