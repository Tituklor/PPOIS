// exceptions/MembershipExpiredException.cpp
#include "MembershipExpiredException.h"
#include <string>

MembershipExpiredException::MembershipExpiredException(int memberId)
        : BaseException("Membership expired for member ID " + std::to_string(memberId)),
          memberId_(memberId) {}

int MembershipExpiredException::getMemberId() const {
    return memberId_;
}