#include "reflector_defs.h"

Reflector::Reflector(bool is_polished, double dimensions)
        : is_polished(is_polished), dimensions(dimensions)
{
}

Reflector::Reflector() : is_polished(true), dimensions(0)
{
}

bool Reflector::check_polished_status()
{
    return is_polished;
}
