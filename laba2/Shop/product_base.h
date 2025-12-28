#ifndef PRODUCT_BASE_H
#define PRODUCT_BASE_H

class ProductBase
{
protected:
    double unit_price;

public:
    ProductBase(const double unit_price);
    double retrieve_price() const;
};

#endif
