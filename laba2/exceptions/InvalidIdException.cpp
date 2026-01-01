// exceptions/InvalidIdException.cpp
#include "InvalidIdException.h"
#include <string>

InvalidIdException::InvalidIdException(int id)
        : BaseException("ID " + std::to_string(id) + " not found"), id_(id) {}

int InvalidIdException::getId() const {
    return id_;
}