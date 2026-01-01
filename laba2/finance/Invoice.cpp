// finance/Invoice.cpp
#include "Invoice.h"
#include <string>

Invoice::Invoice(int paymentId, double amount, const std::string& currency)
        : paymentId_(paymentId), amount_(amount), currency_(currency) {
    // Simple invoice number: INV-{paymentId}
    number_ = "INV-" + std::to_string(paymentId);
}

int Invoice::getPaymentId() const {
    return paymentId_;
}

double Invoice::getAmount() const {
    return amount_;
}

std::string Invoice::getCurrency() const {
    return currency_;
}

std::string Invoice::getNumber() const {
    return number_;
}