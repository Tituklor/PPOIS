// exceptions/InvalidRoleException.h
#ifndef SPORTCLUB_INVALIDROLEEXCEPTION_H
#define SPORTCLUB_INVALIDROLEEXCEPTION_H

#include "BaseException.h"

class InvalidRoleException : public BaseException {
public:
    InvalidRoleException(const std::string& role);
    std::string getRole() const;
private:
    std::string role_;
};

#endif // SPORTCLUB_INVALIDROLEEXCEPTION_H