#include <iostream>
#include <ctime>
#include <cstdlib>

#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "phase.h"

int main() {

    srand(time(0));  // FIRST STATEMENT — ensures true randomness

    Die die1;
    Die die2;

    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out_phase;

    // ------------------- COME OUT PHASE -------------------
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
           come_out_phase.get_outcome(roll) == RollOutcome::craps)
    {
        std::cout << "Rolled " << rolled_value << " roll again\n";

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    // Out of loop: this roll establishes the point
    std::cout << "Rolled " << rolled_value << " start of point phase\n";
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled\n";

    int point = rolled_value;

    // first roll in point phase
    roll = shooter.throw_dice(die1, die2);
    rolled_value = roll->roll_value();

    PointPhase point_phase(point);

    // ------------------- POINT PHASE -------------------
    while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
           point_phase.get_outcome(roll) != RollOutcome::nopoint)
    {
        std::cout << "Rolled " << rolled_value << " roll again\n";

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    // Out of loop
    std::cout << "Rolled " << rolled_value << " end of point phase\n\n";

    // ------------------- DISPLAY ALL ROLLS -------------------
    shooter.display_rolled_values();

    return 0;
}
