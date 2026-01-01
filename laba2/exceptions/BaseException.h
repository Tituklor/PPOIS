// exceptions/BaseException.h
#ifndef SPORTCLUB_BASEEXCEPTION_H
#define SPORTCLUB_BASEEXCEPTION_H

#include <stdexcept>
#include <string>

class BaseException : public std::runtime_error {
public:
    BaseException(const std::string& message);
};

#endif // SPORTCLUB_BASEEXCEPTION_H