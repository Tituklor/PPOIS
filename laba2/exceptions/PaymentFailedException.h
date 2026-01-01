// exceptions/PaymentFailedException.h
#ifndef SPORTCLUB_PAYMENTFAILEDEXCEPTION_H
#define SPORTCLUB_PAYMENTFAILEDEXCEPTION_H

#include "BaseException.h"

class PaymentFailedException : public BaseException {
public:
    PaymentFailedException(const std::string& reason, double amount);
    std::string getReason() const;
    double getAmount() const;
private:
    std::string reason_;
    double amount_;
};

#endif // SPORTCLUB_PAYMENTFAILEDEXCEPTION_H