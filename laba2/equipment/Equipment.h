// equipment/Equipment.h
#ifndef SPORTCLUB_EQUIPMENT_H
#define SPORTCLUB_EQUIPMENT_H

#include <string>

class Equipment {
public:
    Equipment(const std::string& type, int quantity, double rentalFee,
              const std::string& condition);

    std::string getType() const;
    int getQuantity() const;
    double getRentalFee() const;
    std::string getCondition() const;
    void setQuantity(int quantity);
    void setCondition(const std::string& condition);
    bool isAvailable() const;

private:
    std::string type_;
    int quantity_;
    double rentalFee_;
    std::string condition_; // "new", "good", "worn"
};

#endif // SPORTCLUB_EQUIPMENT_H