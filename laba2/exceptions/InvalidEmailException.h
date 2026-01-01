// exceptions/InvalidEmailException.h
#ifndef SPORTCLUB_INVALIDEMAILEXCEPTION_H
#define SPORTCLUB_INVALIDEMAILEXCEPTION_H

#include "BaseException.h"

class InvalidEmailException : public BaseException {
public:
    InvalidEmailException(const std::string& email);
    std::string getEmail() const;
private:
    std::string email_;
};

#endif // SPORTCLUB_INVALIDEMAILEXCEPTION_H