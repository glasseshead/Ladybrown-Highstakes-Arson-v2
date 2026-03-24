#include "midgoal.hpp"

// reset mid goal values

// was mid goal toggled just now?
// no, so it is false
bool midGoalPressed = false;
int midGoalState = 0;

void updateMidGoal() {
    // state = 0: down
    // state = 1: up

    // if a is pressed
    if (controller.get_digital(midGoalControl)) {
        if (!midGoalPressed) {
            // if mid goal is down put it up
            if(midGoalState == 0) {
                midGoalState = 1;
            }

            // if mid goal is up put it down
            else {
                midGoalState = 0;
            }
        }
        // mid goal was just toggled just now
        midGoalPressed = true;

    } 
    // midGoal was not toggled just now
    else {
        midGoalPressed = false;
    }
}

void runMidGoal() {
    while (true) {
        // based on our mid goal state, we toggle it up or down
        switch (midGoalState) {
            // mid goal down
            case 0:
                midGoalPiston.set_value(false);
            // mid goal up
            case 1:
                midGoalPiston.set_value(true);
        }
    }
}