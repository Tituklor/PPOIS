// exceptions/InvalidAgeException.cpp
#include "InvalidAgeException.h"
#include <string>

InvalidAgeException::InvalidAgeException(int age)
        : BaseException("Age " + std::to_string(age) + " is invalid"), age_(age) {}

int InvalidAgeException::getAge() const {
    return age_;
}