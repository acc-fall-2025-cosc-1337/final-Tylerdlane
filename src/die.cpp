#include "die.h"
#include <random>

int Die::roll() {
    // True random seed
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, sides);

    return dist(gen);
}
