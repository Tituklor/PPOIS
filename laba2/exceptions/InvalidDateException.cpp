// exceptions/InvalidDateException.cpp
#include "InvalidDateException.h"

InvalidDateException::InvalidDateException(const std::string& dateStr)
        : BaseException("Invalid date: " + dateStr), date_(dateStr) {}

std::string InvalidDateException::getDate() const {
    return date_;
}