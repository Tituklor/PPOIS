// exceptions/InvalidPhoneNumberException.h
#ifndef SPORTCLUB_INVALIDPHONENUMBEREXCEPTION_H
#define SPORTCLUB_INVALIDPHONENUMBEREXCEPTION_H

#include "BaseException.h"

class InvalidPhoneNumberException : public BaseException {
public:
    InvalidPhoneNumberException(const std::string& phone);
    std::string getPhone() const;
private:
    std::string phone_;
};

#endif // SPORTCLUB_INVALIDPHONENUMBEREXCEPTION_H