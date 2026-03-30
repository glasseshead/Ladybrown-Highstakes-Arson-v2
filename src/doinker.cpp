#include "doinker.hpp"

// reset doinker values

// was doinker toggled just now?
// no, so it is false
bool doinkerPressed = false;
int doinkerState = 0;

void updateDoinker() {
    // state = 0: down
    // state = 1: up

    // if doinker control is pressed
    if (controller.get_digital(doinkerControl)) {
        if (!doinkerPressed) {
            // if doinker is down put it up
            if(doinkerState == 0) {
                doinkerState = 1;
            }

            // if doinker is up put it down
            else {
                doinkerState = 0;
            }
        }
        // doinker was just toggled just now
        doinkerPressed = true;

    } 
    // doinker was not toggled just now
    else {
        doinkerPressed = false;
    }
}

void runDoinker() {
    while (true) {
        // based on our doinker state, we toggle it up or down
        switch (doinkerState) {
            // doinker down
            case 0:
                doinkerPistons.set_value(false);
            // doinker up
            case 1:
                doinkerPistons.set_value(true);
        }
    }
}