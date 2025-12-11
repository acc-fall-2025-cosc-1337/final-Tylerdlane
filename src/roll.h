#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    // Constructor takes two Die references
    Roll(Die& d1, Die& d2);

    // Rolls both dice and stores the value
    void roll_dice();

    // Returns the stored roll value
    int roll_value() const;

private:
    Die& die1;
    Die& die2;
    int rolled_value {0};
};

#endif
