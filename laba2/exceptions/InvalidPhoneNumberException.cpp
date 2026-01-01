// exceptions/InvalidPhoneNumberException.cpp
#include "InvalidPhoneNumberException.h"

InvalidPhoneNumberException::InvalidPhoneNumberException(const std::string& phone)
        : BaseException("Invalid phone: " + phone), phone_(phone) {}

std::string InvalidPhoneNumberException::getPhone() const {
    return phone_;
}