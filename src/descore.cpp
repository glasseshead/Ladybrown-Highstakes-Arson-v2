#include "descore.hpp"

// reset descore wing values

// was descore wing toggled just now?
// no, so it is false
bool descorePressed = false;
int descoreState = 0;

void updateDescore() {
    // state = 0: down
    // state = 1: up

    // if a is pressed
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        if (!descorePressed) {
            // if descore wing is down put it up
            if(descoreState == 0) {
                descoreState = 1;
            }

            // if descore wing is up put it down
            else {
                descoreState = 0;
            }
        }
        // descore wing was just toggled just now
        descorePressed = true;

    } 
    // descore wing was not toggled just now
    else {
        descorePressed = false;
    }
}

void runDescore() {
    while (true) {
        // based on our descore wing state, we toggle it on or off
        switch (descoreState) {
            // descore wing down
            case 0:
                descorePiston.set_value(false);
            // descore wing up
            case 1:
                descorePiston.set_value(true);
        }
    }
}