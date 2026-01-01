// manager/PaymentManager.h
#ifndef SPORTCLUB_PAYMENTMANAGER_H
#define SPORTCLUB_PAYMENTMANAGER_H

#include "../finance/Payment.h"
#include <vector>

class PaymentManager {
public:
    void addPayment(const Payment& payment);
    Payment* findPaymentByMemberId(int memberId);
    std::vector<Payment> getPaymentsByMember(int memberId) const;
    size_t getPaymentCount() const;
    double getTotalRevenue() const;

private:
    std::vector<Payment> payments_;
};

#endif // SPORTCLUB_PAYMENTMANAGER_H