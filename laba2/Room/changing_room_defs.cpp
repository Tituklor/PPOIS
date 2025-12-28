#include "changing_room_defs.h"
#include <algorithm>

ChangingRoom::ChangingRoom(const double room_area,
                           WeightScale weight_scales, const char room_gender)
        : Space(room_area), weight_scales(weight_scales), room_gender(room_gender)
{
}

char ChangingRoom::retrieve_gender()
{
    return room_gender;
}

void ChangingRoom::install_storage_unit(const unsigned int unit_number)
{
    auto position = std::lower_bound(storage_units.begin(), storage_units.end(),
                                     unit_number, [](const StorageUnit& unit, unsigned int num) {
                return unit.num < num;
            });
    storage_units.insert(position, StorageUnit(room_gender, unit_number));
}
