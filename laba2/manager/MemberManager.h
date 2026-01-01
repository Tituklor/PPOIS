// manager/MemberManager.h
#ifndef SPORTCLUB_MEMBERMANAGER_H
#define SPORTCLUB_MEMBERMANAGER_H

#include "../core/Member/Member.h"
#include <vector>

class MemberManager {
public:
    void addMember(const Member& member);
    void removeMember(int memberId);
    Member* findMemberById(int id);
    std::vector<Member> getAllMembers() const;
    size_t getMemberCount() const;
    bool hasActiveMembership(int memberId) const;
    void updateMemberContact(int memberId, const std::string& phone, const std::string& email);

private:
    std::vector<Member> members_;
};

#endif // SPORTCLUB_MEMBERMANAGER_H