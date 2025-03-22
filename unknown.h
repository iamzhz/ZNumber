#ifndef _Z_NUMBER_UNKNOWN_H_
#define _Z_NUMBER_UNKNOWN_H_

#include "rational.h"

// always use pointer for Z_unknown -> Z_unknown *
class Z_unknown {
    public:
    // `n` could be `a`-`z` and `A`-`Z`
    char n;
    Z_rational v; // value
}

#endif