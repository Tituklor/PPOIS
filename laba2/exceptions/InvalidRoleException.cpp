// exceptions/InvalidRoleException.cpp
#include "InvalidRoleException.h"

InvalidRoleException::InvalidRoleException(const std::string& role)
        : BaseException("Invalid role: " + role), role_(role) {}

std::string InvalidRoleException::getRole() const {
    return role_;
}