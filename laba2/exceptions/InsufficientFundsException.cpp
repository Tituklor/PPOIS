// exceptions/InsufficientFundsException.cpp
#include "InsufficientFundsException.h"
#include <string>

InsufficientFundsException::InsufficientFundsException(double balance, double required)
        : BaseException("Insufficient funds: have " + std::to_string(balance) +
                        ", need " + std::to_string(required)),
          balance_(balance), required_(required) {}

double InsufficientFundsException::getBalance() const {
    return balance_;
}

double InsufficientFundsException::getRequired() const {
    return required_;
}