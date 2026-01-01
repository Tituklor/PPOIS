// exceptions/EquipmentUnavailableException.cpp
#include "EquipmentUnavailableException.h"
#include <string>

EquipmentUnavailableException::EquipmentUnavailableException(
        const std::string& equipmentType, int requested)
        : BaseException("Equipment '" + equipmentType + "' unavailable. Requested: " +
                        std::to_string(requested)),
          equipmentType_(equipmentType), requested_(requested) {}

std::string EquipmentUnavailableException::getEquipmentType() const {
    return equipmentType_;
}

int EquipmentUnavailableException::getRequested() const {
    return requested_;
}