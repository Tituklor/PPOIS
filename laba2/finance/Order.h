// finance/Order.h
#ifndef SPORTCLUB_ORDER_H
#define SPORTCLUB_ORDER_H

#include <string>

class Order {
public:
    Order(int memberId, const std::string& service, double amount);

    int getMemberId() const;
    std::string getService() const;
    double getAmount() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);

private:
    int memberId_;
    std::string service_; // e.g., "Cafe", "Locker", "Towel"
    double amount_;
    std::string status_;
};

#endif // SPORTCLUB_ORDER_H