#ifndef ACCESS_DEFS_H
#define ACCESS_DEFS_H

#include <string>


class StorageUnit;
class PersonBase;
class FrontDeskStaff;
class KeyRack;

class PassKey
{
    // Friend declarations
    friend class StorageUnit;
    friend class KeyRack;
    friend class FrontDeskStaff;

private:
    StorageUnit* storage_unit;
    unsigned int key_number;
    PersonBase* key_holder;
    char gender_code;

    void assign_holder(PersonBase* holder);
    void detach_from_holder();

public:
    PassKey();
    PassKey(StorageUnit* storage_unit, unsigned int key_number, char gender_code);

    unsigned int retrieve_key_number();
    void secure_storage();
    void unlock_storage();
    void connect_to_storage(StorageUnit* new_unit);
    void disconnect_storage();
    std::string retrieve_gender();
    bool is_male_key();
    bool is_female_key();
};

#endif // ACCESS_DEFS_H
