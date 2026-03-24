#include "matchloader.hpp"

// reset matchloader values

// was matchloader toggled just now?
// no, so it is false
bool matchLoaderPressed = false;
int matchLoaderState = 0;

void updateMatchLoader() {
    // state = 0: down
    // state = 1: up

    // if matchloader control is pressed
    if (controller.get_digital(matchloaderControl)) {
        if (!matchLoaderPressed) {
            // if matchloader is down put it up
            if(matchLoaderState == 0) {
                matchLoaderState = 1;
            }

            // if matchloader is up put it down
            else {
                matchLoaderState = 0;
            }
        }
        // matchloader was just toggled just now
        matchLoaderPressed = true;

    } 
    // matchloader was not toggled just now
    else {
        matchLoaderPressed = false;
    }
}

void runMatchLoader() {
    while (true) {
        // based on our matchloader state, we toggle it up or down
        switch (matchLoaderState) {
            // matchloader down
            case 0:
                matchLoaderPiston_L.set_value(false);
                matchLoaderPiston_R.set_value(false);
            // matchloader up
            case 1:
                matchLoaderPiston_L.set_value(true);
                matchLoaderPiston_R.set_value(true);
        }
    }
}