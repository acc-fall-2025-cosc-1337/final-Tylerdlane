#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& d1, Die& d2) {
    Roll* r = new Roll(d1, d2); // dynamic allocation
    r->roll_dice();             // roll the dice
    rolls.push_back(r);         // store in vector
    return r;                   // return pointer
}

void Shooter::display_rolled_values() {
    for (Roll* r : rolls) {
        std::cout << r->roll_value() << " ";
    }
    std::cout << "\n";
}

Shooter::~Shooter() {
    // delete all dynamically allocated Roll objects
    for (Roll* r : rolls) {
        delete r;
    }
    rolls.clear();
}
