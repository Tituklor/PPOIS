// exceptions/InvalidDateException.h
#ifndef SPORTCLUB_INVALIDDATEEXCEPTION_H
#define SPORTCLUB_INVALIDDATEEXCEPTION_H

#include "BaseException.h"

class InvalidDateException : public BaseException {
public:
    InvalidDateException(const std::string& dateStr);
    std::string getDate() const;
private:
    std::string date_;
};

#endif // SPORTCLUB_INVALIDDATEEXCEPTION_H