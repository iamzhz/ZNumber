#ifndef _Z_NUMBER_POWER_H_
#define _Z_NUMBER_POWER_H_

#include "rational.h"
#include "unknown.h"

class Z_power {
    // means [an unknown number ^ a rational number] like `x^2`
    // u^{exp}
    bool is_exist;
    Z_unknown * u;  // unknown number
    Z_rational * exp;  // exponential

    Z_power();
    Z_power(bool is_exist);
};

#endif