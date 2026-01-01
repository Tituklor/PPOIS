// core/Member/Member.cpp
#include "Member.h"
#include "../../config/Config.h"

Member::Member(const std::string& name, int age,
               const std::string& phoneNumber, const std::string& email,
               int id)
        : Person(name, age, phoneNumber, email), id_(id),
          membershipStatus_(Config::STATUS_ACTIVE) {}

int Member::getId() const {
    return id_;
}

std::string Member::getMembershipStatus() const {
    return membershipStatus_;
}

void Member::setMembershipStatus(const std::string& status) {
    membershipStatus_ = status;
}

bool Member::hasActiveMembership() const {
    return membershipStatus_ == Config::STATUS_ACTIVE;
}