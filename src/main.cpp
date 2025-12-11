#include <iostream>
#include <cassert>
#include "die.h"

int main() {
    Die d;

    for (int i = 0; i < 10; i++) {
        int value = d.roll();
        std::cout << "Roll " << i + 1 << ": " << value << "\n";

        // Assert the value is between 1 and 6
        assert(value >= 1 && value <= 6);
    }

    std::cout << "All tests passed!\n";
    return 0;
}
