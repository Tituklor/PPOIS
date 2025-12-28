#include "storage_defs.h"
#include "../Human/error_defs.h"

StorageUnit::StorageUnit(const char unit_gender, const unsigned int unit_number)
        : unit_number(unit_number)
        , secured_status(false)
        , is_connected(false)
        , access_key(nullptr)
        , unit_gender(unit_gender)
        , storage_capacity(0)
        , is_defective(false)
        , has_airflow(false)
        , has_reflector(false)
        , unit_material("")
        , unit_color("")
        , unit_reflector()
{
}

StorageUnit::StorageUnit(PassKey* key, const unsigned int unit_number, char unit_gender,
                         unsigned int storage_capacity, bool is_defective,
                         bool has_airflow, bool has_reflector, std::string unit_material,
                         std::string unit_color)
        : unit_number(unit_number)
        , secured_status(true)
        , is_connected(true)
        , access_key(key)
        , unit_gender(unit_gender)
        , storage_capacity(storage_capacity)
        , is_defective(is_defective)
        , has_airflow(has_airflow)
        , has_reflector(has_reflector)
        , unit_material(unit_material)
        , unit_color(unit_color)
        , unit_reflector()
{
    connect_key(key);
}

bool StorageUnit::check_defective_status() const {
    return is_defective;
}

std::string StorageUnit::retrieve_unit_color() const {
    return unit_color;
}

std::string StorageUnit::retrieve_unit_material() const {
    return unit_material;
}

bool StorageUnit::has_reflector_installed() const {
    return has_reflector;
}

bool StorageUnit::has_airflow_system() const {
    return has_airflow;
}

unsigned int StorageUnit::retrieve_storage_capacity() const {
    return storage_capacity;
}

bool StorageUnit::is_secured() const {
    return secured_status;
}

bool StorageUnit::is_accessible() const {
    return access_key != nullptr && !is_defective;
}

void StorageUnit::connect_key(PassKey* key) {
    access_key = key;
    if (key) {
        key->connect_to_storage(this);
        secured_status = true;
        is_connected = true;
    }
}

void StorageUnit::disconnect_key() {
    if (access_key) {
        access_key->disconnect_storage();
        access_key = nullptr;
        secured_status = false;
        is_connected = false;
    }
}
