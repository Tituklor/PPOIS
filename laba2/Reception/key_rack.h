#ifndef KEY_RACK_H
#define KEY_RACK_H

#include <vector>
#include "../Human/frontdesk_defs.h"
#include "../Reception/access_defs.h"

class Membership;
class PassKey;

class KeyRack
{
    friend class FrontDeskStaff;

    std::vector<std::pair<PassKey, Membership*>> key_slots;

public:
    void store_key(PassKey access_key);
    bool check_empty_status();
};

#endif
