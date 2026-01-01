// core/Member/Member.h
#ifndef SPORTCLUB_MEMBER_H
#define SPORTCLUB_MEMBER_H

#include "../Person/Person.h"
#include <string>

class Member : public Person {
public:
    Member(const std::string& name, int age,
           const std::string& phoneNumber, const std::string& email,
           int id);

    int getId() const;
    std::string getMembershipStatus() const;
    void setMembershipStatus(const std::string& status);
    bool hasActiveMembership() const;

private:
    int id_;
    std::string membershipStatus_;
};

#endif // SPORTCLUB_MEMBER_H