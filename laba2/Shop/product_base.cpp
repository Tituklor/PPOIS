#include "product_base.h"
#include "../Human/error_defs.h"

ProductBase::ProductBase(const double unit_price)
        : unit_price(unit_price)
{
    if (unit_price <= 0)
        throw InvalidPriceError("Неположительная стоимость");
}

double ProductBase::retrieve_price() const
{
    return unit_price;
}
