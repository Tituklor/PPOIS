#ifndef REFLECTOR_DEFS_H
#define REFLECTOR_DEFS_H

#include <string>

class Janitor;

class Reflector
{
    friend class Janitor;

    bool is_polished;
    double dimensions;

private:
    bool cleaned;  // ✅

public:
    Reflector(bool is_polished, double dimensions);
    Reflector();
    bool check_polished_status();
};

#endif
