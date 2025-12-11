#include <iostream>
#include <cassert>

#include "die.h"
#include "roll.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"


class TestRoll : public Roll {
public:
    TestRoll(int value)
        : Roll(dummy, dummy), forced_value(value) {}

    int roll_value() const override {
        return forced_value;
    }

private:
    static Die dummy;
    int forced_value;
};

Die TestRoll::dummy;

// -----------------------------------------------------------
// MAIN – tests ComeOutPhase and PointPhase
// -----------------------------------------------------------
int main() {

    ComeOutPhase come_out;
    PointPhase point_phase(5);  // example point = 5

    // -------------------------------------------------------
    // Test ComeOutPhase
    // -------------------------------------------------------

    // NATURAL: 7, 11
    assert(come_out.get_outcome(new TestRoll(7)) == RollOutcome::natural);
    assert(come_out.get_outcome(new TestRoll(11)) == RollOutcome::natural);

    // CRAPS: 2, 3, 12
    assert(come_out.get_outcome(new TestRoll(2)) == RollOutcome::craps);
    assert(come_out.get_outcome(new TestRoll(3)) == RollOutcome::craps);
    assert(come_out.get_outcome(new TestRoll(12)) == RollOutcome::craps);

    // POINT (any other valid value)
    assert(come_out.get_outcome(new TestRoll(4)) == RollOutcome::point);
    assert(come_out.get_outcome(new TestRoll(5)) == RollOutcome::point);
    assert(come_out.get_outcome(new TestRoll(6)) == RollOutcome::point);
    assert(come_out.get_outcome(new TestRoll(8)) == RollOutcome::point);
    assert(come_out.get_outcome(new TestRoll(9)) == RollOutcome::point);
    assert(come_out.get_outcome(new TestRoll(10)) == RollOutcome::point);

    std::cout << "ComeOutPhase tests passed.\n";

    // -------------------------------------------------------
    // Test PointPhase (point = 5)
    // -------------------------------------------------------

    // Hit the point
    assert(point_phase.get_outcome(new TestRoll(5)) == RollOutcome::point);

    // Seven-out
    assert(point_phase.get_outcome(new TestRoll(7)) == RollOutcome::seven_out);

    // No point
    assert(point_phase.get_outcome(new TestRoll(8)) == RollOutcome::nopoint);
    assert(point_phase.get_outcome(new TestRoll(9)) == RollOutcome::nopoint);
    assert(point_phase.get_outcome(new TestRoll(4)) == RollOutcome::nopoint);

    std::cout << "PointPhase tests passed.\n";

    std::cout << "ALL TESTS PASSED!\n";
    return 0;
}
