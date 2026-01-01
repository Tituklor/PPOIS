// manager/EquipmentManager.cpp
#include "EquipmentManager.h"
#include "../exceptions/EquipmentUnavailableException.h"

void EquipmentManager::addEquipment(const Equipment& equipment) {
    equipmentList_.push_back(equipment);
}

Equipment* EquipmentManager::findEquipmentByType(const std::string& type) {
    for (auto& eq : equipmentList_) {
        if (eq.getType() == type) {
            return &eq;
        }
    }
    return nullptr;
}

std::vector<Equipment> EquipmentManager::getAllEquipment() const {
    return equipmentList_;
}

size_t EquipmentManager::getEquipmentCount() const {
    return equipmentList_.size();
}

bool EquipmentManager::rentEquipment(const std::string& type, int quantity) {
    Equipment* eq = findEquipmentByType(type);
    if (!eq || eq->getQuantity() < quantity) {
        throw EquipmentUnavailableException(type, quantity);
    }
    eq->setQuantity(eq->getQuantity() - quantity);
    return true;
}

void EquipmentManager::returnEquipment(const std::string& type, int quantity) {
    Equipment* eq = findEquipmentByType(type);
    if (eq) {
        eq->setQuantity(eq->getQuantity() + quantity);
    }
}