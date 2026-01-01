// membership/Membership.h
#ifndef SPORTCLUB_MEMBERSHIP_H
#define SPORTCLUB_MEMBERSHIP_H

#include "MembershipPlan.h"
#include <string>

class Membership {
public:
    Membership(int memberId, const MembershipPlan& plan);

    int getMemberId() const;
    MembershipPlan getPlan() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isActive() const;

private:
    int memberId_;
    MembershipPlan plan_;
    std::string status_;
};

#endif // SPORTCLUB_MEMBERSHIP_H