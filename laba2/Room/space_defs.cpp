#include "space_defs.h"
#include "../Human/error_defs.h"

Space::Space(const double space_area)
        : space_area(space_area),
          is_sanitized(true),
          cleaned(false)  // ← ИНИЦИАЛИЗАЦИЯ нового поля!
{
    if (space_area <= 0)
        throw InvalidAreaError("Площадь не может быть отрицательной либо быть равной 0");
}

Space::Space(const double space_area, const bool is_sanitized)
        : space_area(space_area),
          is_sanitized(is_sanitized),
          cleaned(false)  // ← ИНИЦИАЛИЗАЦИЯ нового поля!
{
    if (space_area <= 0)
        throw InvalidAreaError("Площадь не может быть отрицательной либо быть равной 0");
}

bool Space::check_sanitized_status() const {
    return is_sanitized;
}

bool Space::is_cleaned() const {
    return cleaned;
}

void Space::set_cleaned(bool status) {
    cleaned = status;
}
