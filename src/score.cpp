#include "score.hpp"

// reset score values

// was score toggled just now?
// no, so it is false
bool scorePressed = false;
int scoreState = 0;

void updateScore() {
    // state = 1: score
    // state = 0: off

    // if L1 is pressed
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        if (!scorePressed_intaking) {
            // if it is on turn it off
            if(scoreState == 1) {
                scoreState = 0;
            }

            // if it is off turn it on
            else {
                scoreState = 1;
            }
        }
        // score was just toggled just now
        scorePressed_intaking = true;

    } 
    // score was not toggled just now
    else {
        scorePressed_intaking = false;
    }
}

void runScore() {
    while (true) {
        // based on our score state, we toggle it on or off
        switch (scoreState) {
            // scoring
            case 1:
                score.move_voltage(127);
                storage.move_voltage(127);
            // off
            case 0:
                score.move_voltage(0);
        }
    }
}