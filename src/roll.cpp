#include "roll.h"

Roll::Roll(Die& d1, Die& d2)
    : die1(d1), die2(d2)  // initializer list
{
}

void Roll::roll_dice() {
    int v1 = die1.roll();
    int v2 = die2.roll();
    rolled_value = v1 + v2;
}

int Roll::roll_value() const {
    return rolled_value;
}
