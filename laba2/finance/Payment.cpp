// finance/Payment.cpp
#include "Payment.h"
#include "../config/Config.h"

Payment::Payment(int memberId, double amount, const std::string& description)
        : memberId_(memberId), amount_(amount), description_(description),
          status_("pending") {}

int Payment::getMemberId() const {
    return memberId_;
}

double Payment::getAmount() const {
    return amount_;
}

std::string Payment::getDescription() const {
    return description_;
}

std::string Payment::getStatus() const {
    return status_;
}

void Payment::setStatus(const std::string& status) {
    status_ = status;
}

bool Payment::isSuccess() const {
    return status_ == "completed";
}