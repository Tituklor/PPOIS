// exceptions/InsufficientFundsException.h
#ifndef SPORTCLUB_INSUFFICIENTFUNDSEXCEPTION_H
#define SPORTCLUB_INSUFFICIENTFUNDSEXCEPTION_H

#include "BaseException.h"

class InsufficientFundsException : public BaseException {
public:
    InsufficientFundsException(double balance, double required);
    double getBalance() const;
    double getRequired() const;
private:
    double balance_;
    double required_;
};

#endif // SPORTCLUB_INSUFFICIENTFUNDSEXCEPTION_H