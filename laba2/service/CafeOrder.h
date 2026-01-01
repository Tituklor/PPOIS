// service/CafeOrder.h
#ifndef SPORTCLUB_CAFEORDER_H
#define SPORTCLUB_CAFEORDER_H

#include <string>

class CafeOrder {
public:
    CafeOrder(int memberId, const std::string& item, double price);

    int getMemberId() const;
    std::string getItem() const;
    double getPrice() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);

private:
    int memberId_;
    std::string item_;
    double price_;
    std::string status_;
};

#endif // SPORTCLUB_CAFEORDER_H