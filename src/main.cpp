#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"
#include "shooter.h"

int main() {
    Die d1;
    Die d2;
    Shooter shooter;

    for (int i = 0; i < 10; i++) {
        Roll* r = shooter.throw_dice(d1, d2);
        int value = r->roll_value();

        std::cout << "Shot " << i + 1 << ": " << value << "\n";

        // Assert valid roll (2–12)
        assert(value >= 2 && value <= 12);
    }

    std::cout << "All shooter tests passed!\n";

    return 0;
}
