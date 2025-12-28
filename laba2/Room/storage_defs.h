#ifndef STORAGE_DEFS_H
#define STORAGE_DEFS_H

#include <string>

// ✅ Forward declarations вместо циклических include!
class PassKey;
class ChangingRoom;
class Reflector;

class StorageUnit
{
    friend class PassKey;
    friend class ChangingRoom;

private:
    unsigned int unit_number;        // ✅ вместо "num"
    bool secured_status;             // ✅ вместо "locked"
    bool is_connected;
    PassKey* access_key;             // ✅ вместо "passkey"
    char unit_gender;                // 'f' = female, 'm' = male
    unsigned int storage_capacity;
    bool is_defective;
    bool has_airflow;
    bool has_reflector;
    std::string unit_material;
    std::string unit_color;
    Reflector unit_reflector;

public:
    // Конструкторы
    StorageUnit(const char unit_gender, const unsigned int unit_number);
    StorageUnit(PassKey* access_key, const unsigned int unit_number, char unit_gender,
                unsigned int storage_capacity, bool is_defective,
                bool has_airflow, bool has_reflector, std::string unit_material,
                std::string unit_color);

    // ✅ Геттеры состояния
    bool check_defective_status() const;
    bool is_secured() const;
    bool is_accessible() const;
    bool is_locked() const { return secured_status; }  // ✅ Для access_defs.cpp

    // ✅ Геттеры характеристик
    std::string retrieve_unit_color() const;
    std::string retrieve_unit_material() const;
    bool has_reflector_installed() const;
    bool has_airflow_system() const;
    unsigned int retrieve_storage_capacity() const;
    unsigned int get_unit_number() const;  // ✅ Для changing_room_defs.cpp

    // ✅ Методы управления доступом
    void connect_key(PassKey* key);
    void disconnect_key();
    void detach_key();  // ✅ Для access_defs.cpp
};

#endif // STORAGE_DEFS_H
