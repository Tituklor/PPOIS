// equipment/Equipment.cpp
#include "Equipment.h"

Equipment::Equipment(const std::string& type, int quantity, double rentalFee,
                     const std::string& condition)
        : type_(type), quantity_(quantity), rentalFee_(rentalFee), condition_(condition) {}

std::string Equipment::getType() const {
    return type_;
}

int Equipment::getQuantity() const {
    return quantity_;
}

double Equipment::getRentalFee() const {
    return rentalFee_;
}

std::string Equipment::getCondition() const {
    return condition_;
}

void Equipment::setQuantity(int quantity) {
    quantity_ = quantity;
}

void Equipment::setCondition(const std::string& condition) {
    condition_ = condition;
}

bool Equipment::isAvailable() const {
    return quantity_ > 0;
}