// server/ClubServer.cpp
#include "ClubServer.h"
#include "../core/Member/Member.h"
#include "../core/Coach/Coach.h"
#include "../facility/Facility.h"
#include "../finance/Payment.h"
#include "../schedule/Booking.h"
#include "../service/Locker.h"
#include "../exceptions/InvalidIdException.h"

ClubServer::ClubServer() {}

bool ClubServer::registerMember(const std::string& name, int age,
                                const std::string& phone, const std::string& email) {
    try {
        Member member(name, age, phone, email, nextMemberId_);
        memberManager_.addMember(member);
        nextMemberId_++;
        return true;
    } catch (...) {
        return false;
    }
}

bool ClubServer::hireCoach(const std::string& name, int age,
                           const std::string& phone, const std::string& email,
                           const std::string& specialization) {
    try {
        Coach coach(name, age, phone, email, nextCoachId_, specialization);
        coachManager_.addCoach(coach);
        nextCoachId_++;
        return true;
    } catch (...) {
        return false;
    }
}

bool ClubServer::addFacility(const std::string& name, const std::string& type,
                             int capacity, const std::string& location) {
    try {
        Facility facility(name, type, capacity, location);
        facilityManager_.addFacility(facility);
        return true;
    } catch (...) {
        return false;
    }
}

bool ClubServer::bookSession(int personId, const std::string& facility,
                             const std::string& timeSlot, bool isMember) {
    try {
        Booking booking(personId, facility, timeSlot, isMember);
        bookingManager_.addBooking(booking);
        return true;
    } catch (...) {
        return false;
    }
}

bool ClubServer::processPayment(int memberId, double amount, const std::string& desc) {
    try {
        Payment payment(memberId, amount, desc);
        payment.setStatus("completed");
        paymentManager_.addPayment(payment);
        return true;
    } catch (...) {
        return false;
    }
}

bool ClubServer::rentEquipment(const std::string& type, int quantity) {
    try {
        return equipmentManager_.rentEquipment(type, quantity);
    } catch (...) {
        return false;
    }
}

bool ClubServer::assignLocker(int memberId, int lockerNumber) {
    try {
        // Simple: assume lockers managed externally
        // In real app: LockerManager would exist
        return true;
    } catch (...) {
        return false;
    }
}

Member* ClubServer::getMember(int id) {
    return memberManager_.findMemberById(id);
}

Coach* ClubServer::getCoach(int id) {
    return coachManager_.findCoachById(id);
}

Facility* ClubServer::getFacility(const std::string& name) {
    return facilityManager_.findFacilityByName(name);
}

double ClubServer::getRevenue() const {
    return paymentManager_.getTotalRevenue();
}

size_t ClubServer::getTotalMembers() const {
    return memberManager_.getMemberCount();
}