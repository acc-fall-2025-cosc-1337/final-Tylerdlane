#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"

int main() {
    Die d1;
    Die d2;
    Roll r(d1, d2);

    for (int i = 0; i < 10; i++) {
        r.roll_dice();
        int value = r.roll_value();

        std::cout << "Roll " << i + 1 << ": " << value << "\n";
        assert(value >= 2 && value <= 12);
    }

    std::cout << "All roll tests passed!\n";
    return 0;
}

