// membership/Membership.cpp
#include "Membership.h"
#include "../config/Config.h"

Membership::Membership(int memberId, const MembershipPlan& plan)
        : memberId_(memberId), plan_(plan), status_(Config::STATUS_ACTIVE) {}

int Membership::getMemberId() const {
    return memberId_;
}

MembershipPlan Membership::getPlan() const {
    return plan_;
}

std::string Membership::getStatus() const {
    return status_;
}

void Membership::setStatus(const std::string& status) {
    status_ = status;
}

bool Membership::isActive() const {
    return status_ == Config::STATUS_ACTIVE;
}