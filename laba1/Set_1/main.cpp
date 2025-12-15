#include "Set.h"
#include <iostream>

int main() {
    Set s1("{a, b}");
    Set s2("{b, c}");

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s1 + s2: " << (s1 + s2) << std::endl;

    return 0;
}
