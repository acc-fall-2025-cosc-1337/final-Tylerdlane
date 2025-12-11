#ifndef DIE_H
#define DIE_H

class Die {
public:
    // Rolls the die and returns value from 1–6
    int roll();

private:
    int sides {6}; // number of sides, fixed at 6
};

#endif
