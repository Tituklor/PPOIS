// exceptions/MembershipExpiredException.h
#ifndef SPORTCLUB_MEMBERSHIPEXPIREDEXCEPTION_H
#define SPORTCLUB_MEMBERSHIPEXPIREDEXCEPTION_H

#include "BaseException.h"

class MembershipExpiredException : public BaseException {
public:
    MembershipExpiredException(int memberId);
    int getMemberId() const;
private:
    int memberId_;
};

#endif // SPORTCLUB_MEMBERSHIPEXPIREDEXCEPTION_H