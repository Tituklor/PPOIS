#include "access_defs.h"
#include "../Human/person_base.h"
#include "../Human/error_defs.h"
#include "../Room/storage_defs.h"

PassKey::PassKey()
{
    key_number = 0;
    storage_unit = nullptr;
    gender_code = 'm';
}

PassKey::PassKey(StorageUnit* storage_unit, unsigned int key_number, char gender_code)
{
    if (gender_code != 'm' && gender_code != 'f')
        throw InvalidGenderError("Либо m, либо f");
    this->key_number = key_number;
    this->storage_unit = storage_unit;
    if (storage_unit)
        storage_unit->num = key_number;
    this->gender_code = gender_code;
}

unsigned int PassKey::retrieve_key_number()
{
    return key_number;
}

void PassKey::secure_storage()
{
    if (storage_unit && storage_unit->passkey == this)
        storage_unit->locked = true;
}

void PassKey::unlock_storage()
{
    if (storage_unit && storage_unit->passkey == this)
        storage_unit->locked = false;
}

void PassKey::connect_to_storage(StorageUnit* new_unit)
{
    if (key_holder->key_linking_permitted)
    {
        if (storage_unit && storage_unit->passkey)
        {
            storage_unit->passkey->detach_from_storage();
            storage_unit->detach_key();
        }
        storage_unit = new_unit;
        new_unit->passkey = this;
        key_number = new_unit->num;
    }
}

void PassKey::disconnect_storage()
{
    storage_unit = nullptr;
    key_number = 0;
}

std::string PassKey::retrieve_gender()
{
    if (gender_code == 'm')
        return "male";
    return "female";
}

bool PassKey::is_male_key()
{
    return gender_code == 'm';
}

bool PassKey::is_female_key()
{
    return gender_code == 'f';
}

void PassKey::assign_holder(PersonBase* holder)
{
    key_holder = holder;
}
