#ifndef PHASE_H
#define PHASE_H

#include "roll.h"

// Enum required by the assignment
enum class RollOutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

// Abstract base class
class Phase {
public:
    virtual RollOutcome get_outcome(Roll* roll) = 0;  // pure virtual
    virtual ~Phase() = default;
};

#endif
