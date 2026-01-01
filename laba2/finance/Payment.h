// finance/Payment.h
#ifndef SPORTCLUB_PAYMENT_H
#define SPORTCLUB_PAYMENT_H

#include <string>

class Payment {
public:
    Payment(int memberId, double amount, const std::string& description);

    int getMemberId() const;
    double getAmount() const;
    std::string getDescription() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isSuccess() const;

private:
    int memberId_;
    double amount_;
    std::string description_;
    std::string status_; // "pending", "completed", "failed"
};

#endif // SPORTCLUB_PAYMENT_H