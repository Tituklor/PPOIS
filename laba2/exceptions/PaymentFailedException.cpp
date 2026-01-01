// exceptions/PaymentFailedException.cpp
#include "PaymentFailedException.h"
#include <string>

PaymentFailedException::PaymentFailedException(const std::string& reason, double amount)
        : BaseException("Payment failed: " + reason + ", amount: " + std::to_string(amount)),
          reason_(reason), amount_(amount) {}

std::string PaymentFailedException::getReason() const {
    return reason_;
}

double PaymentFailedException::getAmount() const {
    return amount_;
}