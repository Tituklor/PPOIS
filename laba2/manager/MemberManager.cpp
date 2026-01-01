// manager/MemberManager.cpp
#include "MemberManager.h"
#include "../exceptions/InvalidIdException.h"

void MemberManager::addMember(const Member& member) {
    members_.push_back(member);
}

void MemberManager::removeMember(int memberId) {
    for (auto it = members_.begin(); it != members_.end(); ++it) {
        if (it->getId() == memberId) {
            members_.erase(it);
            return;
        }
    }
    throw InvalidIdException(memberId);
}

Member* MemberManager::findMemberById(int id) {
    for (auto& member : members_) {
        if (member.getId() == id) {
            return &member;
        }
    }
    return nullptr;
}

std::vector<Member> MemberManager::getAllMembers() const {
    return members_;
}

size_t MemberManager::getMemberCount() const {
    return members_.size();
}

bool MemberManager::hasActiveMembership(int memberId) const {
    for (const auto& member : members_) {
        if (member.getId() == memberId) {
            return member.hasActiveMembership();
        }
    }
    return false;
}

void MemberManager::updateMemberContact(int memberId,
                                        const std::string& phone,
                                        const std::string& email) {
    Member* member = findMemberById(memberId);
    if (!member) {
        throw InvalidIdException(memberId);
    }
    member->setPhoneNumber(phone);
    member->setEmail(email);
}