// exceptions/InvalidAgeException.h
#ifndef SPORTCLUB_INVALIDAGEEXCEPTION_H
#define SPORTCLUB_INVALIDAGEEXCEPTION_H

#include "BaseException.h"

class InvalidAgeException : public BaseException {
public:
    InvalidAgeException(int age);
    int getAge() const;
private:
    int age_;
};

#endif // SPORTCLUB_INVALIDAGEEXCEPTION_H