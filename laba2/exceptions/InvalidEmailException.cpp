// exceptions/InvalidEmailException.cpp
#include "InvalidEmailException.h"

InvalidEmailException::InvalidEmailException(const std::string& email)
        : BaseException("Invalid email: " + email), email_(email) {}

std::string InvalidEmailException::getEmail() const {
    return email_;
}