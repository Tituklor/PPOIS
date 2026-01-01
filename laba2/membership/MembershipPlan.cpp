// membership/MembershipPlan.cpp
#include "MembershipPlan.h"
#include "../config/Config.h"

MembershipPlan::MembershipPlan(PlanType type) : type_(type) {}

MembershipPlan::PlanType MembershipPlan::getType() const {
    return type_;
}

double MembershipPlan::getMonthlyFee() const {
    return (type_ == STANDARD) ? Config::MONTHLY_FEE_STANDARD
                               : Config::MONTHLY_FEE_PREMIUM;
}

int MembershipPlan::getDurationDays() const {
    return (type_ == STANDARD) ? Config::MEMBERSHIP_DURATION_STANDARD
                               : Config::MEMBERSHIP_DURATION_PREMIUM;
}

std::string MembershipPlan::getTypeName() const {
    return (type_ == STANDARD) ? "Standard" : "Premium";
}