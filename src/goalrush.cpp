#include "goalrush.hpp"

// reset goal rush values

// was goal rush toggled just now?
// no, so it is false
bool goalRushPressed = false;
int goalRushState = 0;

void updateGoalRush() {
    // state = 0: up
    // state = 1: down

    // if goal rush control is pressed
    if (controller.get_digital(goalRushControl)) {
        if (!goalRushPressed) {
            // if goal rush is up put it down
            if(goalRushState == 0) {
                goalRushState = 1;
            }

            // if goal rush is down put it up
            else {
                goalRushState = 0;
            }
        }
        // goal rush was just toggled just now
        goalRushPressed = true;

    } 
    // goal rush was not toggled just now
    else {
        goalRushPressed = false;
    }
}

void runGoalRush() {
    while (true) {
        // based on our goal rush state, we toggle it up or down
        switch (goalRushState) {
            // goal rush up
            case 0:
                goalRushPiston.set_value(false);
            // goal rush down
            case 1:
                goalRushPiston.set_value(true);
        }
    }
}