// manager/EquipmentManager.h
#ifndef SPORTCLUB_EQUIPMENTMANAGER_H
#define SPORTCLUB_EQUIPMENTMANAGER_H

#include "../equipment/Equipment.h"
#include <vector>

class EquipmentManager {
public:
    void addEquipment(const Equipment& equipment);
    Equipment* findEquipmentByType(const std::string& type);
    std::vector<Equipment> getAllEquipment() const;
    size_t getEquipmentCount() const;
    bool rentEquipment(const std::string& type, int quantity);
    void returnEquipment(const std::string& type, int quantity);

private:
    std::vector<Equipment> equipmentList_;
};

#endif // SPORTCLUB_EQUIPMENTMANAGER_H