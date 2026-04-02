#include "climb.hpp"

// reset climb values

// was climb toggled just now?
// no, so it is false
bool climbPressed = false;
int climbState = 0;

void updateClimb() {
    // state = 0: down
    // state = 1: up

    // if climb control is pressed
    if (controller.get_digital(climbControl)) {
        if (!climbPressed) {
            // if climb is down put it up
            if(climbState == 0) {
                climbState = 1;
            }

            // if climb is up put it down
            else {
                climbState = 0;
            }
        }
        // climb was just toggled just now
        climbPressed = true;

    } 
    // climb was not toggled just now
    else {
        climbPressed = false;
    }
}

void runClimb() {
    while (true) {
        // based on our climb state, we toggle it up or down
        switch (climbState) {
            // climb down
            case 0:
                climbPistons.set_value(false);
            // climb up
            case 1:
                climbPistons.set_value(true);
        }
    }
}