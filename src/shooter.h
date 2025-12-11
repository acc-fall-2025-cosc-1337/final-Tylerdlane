#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"

class Shooter {
public:
    // Throws dice: creates Roll dynamically, rolls it, stores it, returns pointer
    Roll* throw_dice(Die& d1, Die& d2);

    // Displays all rolled values
    void display_rolled_values();

    // Destructor
    ~Shooter();

private:
    std::vector<Roll*> rolls; // dynamic memory storage for Roll pointers
};

#endif
