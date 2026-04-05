#include "ladybrown.hpp"

// reset ladybrown values

// was ladybrown toggled just now?
// no, so it is false
bool ladybrownPressed = false;
int ladybrownState = 0;

void updateLadybrown() {
    // state = 0: ladybrown down
    // state = 1: ladybrown load
    // state = 2: ladybrown score

    // if ladybrown control is pressed
    if (controller.get_digital(ladybrownControl)) {
        if (!ladybrownPressed) {
            // if it is down turn it to load
            if(ladybrownState == 0) {
                ladybrownState = 1;
            }
            // if it is load turn it to score
            if(ladybrownState == 1) {
                ladybrownState = 2;
            }
            // if it is score turn it to down
            if(ladybrownState == 2) {
                ladybrownState = 0;
            }
        }
        // ladybrown was just toggled just now
        ladybrownPressed = true;
    }
    // ladybrown was not toggled just now
    else {
        ladybrownPressed = false;
    }
}

void runLadybrown() {
    while (true) {
        // based on our ladybrown state, we toggle it up or down
        switch (ladybrownState) {
            // ladybrown down 
            case 0: {
                std::int32_t ladybrownPID_target = ladybrownPID_downTarget;
                break;
            }
            // ladybrown loading
            case 1: {
                std::int32_t ladybrownPID_target = ladybrownPID_loadTarget;
                break;
            }
            // ladybrown scoring
            case 2: {
                std::int32_t ladybrownPID_target = ladybrownPID_scoreTarget;
                break;
            }
        }
        float ladybrownPIDout = ladybrownPID.update(ladybrownPID_target - ladybrownRotationSensor.get_position());
        ladybrown.move_voltage(ladybrownPIDout);

		// standard wait 10 ms
		pros::delay(10);  
    }
}