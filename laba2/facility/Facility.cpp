// facility/Facility.cpp
#include "Facility.h"
#include "../config/Config.h"

Facility::Facility(const std::string& name, const std::string& type,
                   int capacity, const std::string& location)
        : name_(name), type_(type), capacity_(capacity),
          location_(location), status_(Config::STATUS_AVAILABLE) {}

std::string Facility::getName() const {
    return name_;
}

std::string Facility::getType() const {
    return type_;
}

int Facility::getCapacity() const {
    return capacity_;
}

std::string Facility::getLocation() const {
    return location_;
}

std::string Facility::getStatus() const {
    return status_;
}

void Facility::setStatus(const std::string& status) {
    status_ = status;
}

bool Facility::isAvailable() const {
    return status_ == Config::STATUS_AVAILABLE;
}