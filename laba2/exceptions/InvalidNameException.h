// exceptions/InvalidNameException.h
#ifndef SPORTCLUB_INVALIDNAMEEXCEPTION_H
#define SPORTCLUB_INVALIDNAMEEXCEPTION_H

#include "BaseException.h"

class InvalidNameException : public BaseException {
public:
    InvalidNameException(const std::string& name);
    std::string getName() const;
private:
    std::string name_;
};

#endif // SPORTCLUB_INVALIDNAMEEXCEPTION_H