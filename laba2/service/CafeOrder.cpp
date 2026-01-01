// service/CafeOrder.cpp
#include "CafeOrder.h"

CafeOrder::CafeOrder(int memberId, const std::string& item, double price)
        : memberId_(memberId), item_(item), price_(price), status_("ordered") {}

int CafeOrder::getMemberId() const {
    return memberId_;
}

std::string CafeOrder::getItem() const {
    return item_;
}

double CafeOrder::getPrice() const {
    return price_;
}

std::string CafeOrder::getStatus() const {
    return status_;
}

void CafeOrder::setStatus(const std::string& status) {
    status_ = status;
}