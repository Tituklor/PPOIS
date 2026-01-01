// finance/Order.cpp
#include "Order.h"

Order::Order(int memberId, const std::string& service, double amount)
        : memberId_(memberId), service_(service), amount_(amount), status_("created") {}

int Order::getMemberId() const {
    return memberId_;
}

std::string Order::getService() const {
    return service_;
}

double Order::getAmount() const {
    return amount_;
}

std::string Order::getStatus() const {
    return status_;
}

void Order::setStatus(const std::string& status) {
    status_ = status;
}