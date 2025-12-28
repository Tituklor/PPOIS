#include "key_rack.h"

void KeyRack::store_key(PassKey access_key)
{
    key_slots.push_back({access_key, nullptr});
}

bool KeyRack::check_empty_status()
{
    return key_slots.size() == 0;
}
