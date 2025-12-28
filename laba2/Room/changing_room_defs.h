#ifndef CHANGING_ROOM_DEFS_H
#define CHANGING_ROOM_DEFS_H

#include <vector>
#include "space_defs.h"
#include "storage_defs.h"
#include "scale_defs.h"

class WeightScale;

class ChangingRoom : public Space
{
public:
    WeightScale weight_scales;
    std::vector<StorageUnit> storage_units;
    char room_gender;

    ChangingRoom(const double room_area, WeightScale weight_scales, const char room_gender);
    char retrieve_gender();
    void install_storage_unit(const unsigned int unit_number);
};

#endif
