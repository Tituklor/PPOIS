// finance/Invoice.h
#ifndef SPORTCLUB_INVOICE_H
#define SPORTCLUB_INVOICE_H

#include <string>

class Invoice {
public:
    Invoice(int paymentId, double amount, const std::string& currency);

    int getPaymentId() const;
    double getAmount() const;
    std::string getCurrency() const;
    std::string getNumber() const;

private:
    int paymentId_;
    double amount_;
    std::string currency_;
    std::string number_;
};

#endif // SPORTCLUB_INVOICE_H