// membership/MembershipPlan.h
#ifndef SPORTCLUB_MEMBERSHIPPLAN_H
#define SPORTCLUB_MEMBERSHIPPLAN_H

#include <string>

class MembershipPlan {
public:
    enum PlanType {
        STANDARD,
        PREMIUM
    };

    MembershipPlan(PlanType type);

    PlanType getType() const;
    double getMonthlyFee() const;
    int getDurationDays() const;
    std::string getTypeName() const;

private:
    PlanType type_;
};

#endif // SPORTCLUB_MEMBERSHIPPLAN_HoneNumber, email) {}