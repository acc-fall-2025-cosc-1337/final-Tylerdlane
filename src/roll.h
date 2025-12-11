#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    Roll(Die& d1, Die& d2);

    void roll_dice();

    // Make this virtual so test subclass can override it.
    virtual int roll_value() const;

    virtual ~Roll() = default;

private:
    Die& die1;
    Die& die2;
    int rolled_value {0};
};

#endif
