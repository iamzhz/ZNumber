#include "rational.h"
#include "unknown.h"

#include "power.h"

Z_power::Z_power() {
    this->is_exist = true;
}

Z_power::Z_power(bool is_exist) {
    this->is_exist = is_exist;
}