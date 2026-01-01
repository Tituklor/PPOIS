// manager/PaymentManager.cpp
#include "PaymentManager.h"

void PaymentManager::addPayment(const Payment& payment) {
    payments_.push_back(payment);
}

Payment* PaymentManager::findPaymentByMemberId(int memberId) {
    for (auto& p : payments_) {
        if (p.getMemberId() == memberId && p.isSuccess()) {
            return &p;
        }
    }
    return nullptr;
}

std::vector<Payment> PaymentManager::getPaymentsByMember(int memberId) const {
    std::vector<Payment> result;
    for (const auto& p : payments_) {
        if (p.getMemberId() == memberId) {
            result.push_back(p);
        }
    }
    return result;
}

size_t PaymentManager::getPaymentCount() const {
    return payments_.size();
}

double PaymentManager::getTotalRevenue() const {
    double sum = 0.0;
    for (const auto& p : payments_) {
        if (p.isSuccess()) {
            sum += p.getAmount();
        }
    }
    return sum;
}