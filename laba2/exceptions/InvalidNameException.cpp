// exceptions/InvalidNameException.cpp
#include "InvalidNameException.h"

InvalidNameException::InvalidNameException(const std::string& name)
        : BaseException("Name '" + name + "' is invalid"), name_(name) {}

std::string InvalidNameException::getName() const {
    return name_;
}