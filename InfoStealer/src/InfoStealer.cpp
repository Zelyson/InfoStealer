#include <iostream>

#include "../include/modules/initialize.hpp"

int WinMain() {
    initialize::init(*__argv);
    return 0;
}
