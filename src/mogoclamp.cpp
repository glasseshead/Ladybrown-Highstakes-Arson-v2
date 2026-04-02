#include "mogoclamp.hpp"

// reset mogo clamp values

// was mogo clamp toggled just now?
// no, so it is false
bool mogoClampPressed = false;
int mogoClampState = 0;

void updateMogoClamp() {
    // state = 0: down
    // state = 1: up

    // if mogo clamp control is pressed
    if (controller.get_digital(MogoClampControl)) {
        if (!mogoClampPressed) {
            // if mogo clamp is down put it up
            if(mogoClampState == 0) {
                mogoClampState = 1;
            }

            // if mogo clamp is up put it down
            else {
                mogoClampState = 0;
            }
        }
        // mogo clamp was just toggled just now
        mogoClampPressed = true;

    } 
    // mogo clamp was not toggled just now
    else {
        mogoClampPressed = false;
    }
}

void runMogoClamp() {
    while (true) {
        // based on our mogo clamp state, we toggle it up or down
        switch (mogoClampState) {
            // mogo clamp down
            case 0:
                mogoClampPiston.set_value(false);
            // mogo clamp up
            case 1:
                mogoClampPiston.set_value(true);
        }
    }
}