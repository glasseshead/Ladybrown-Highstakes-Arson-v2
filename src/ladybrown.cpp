#include "ladybrown.hpp"

// reset ladybrown values

// was ladybrown toggled just now?
// no, so it is false
bool ladybrownPressed = false;
int ladybrownState = 0;

void updateLadybrown() {
    // state = 0: ladybrown down
    // state = 1: ladybrown up

    // if ladybrown control is pressed
    if (controller.get_digital(ladybrownControl)) {
        if (!ladybrownPressed) {
            // if it is down turn it to up
            if(ladybrownState == 0) {
                ladybrownState = 1;
            }
            // if it is up turn it to down
            if(ladybrownState == 1) {
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
            // ladybrown scoring
            case 1: {
                std::int32_t ladybrownPID_target = ladybrownPID_upTarget;
                break;
            }
        }
        float ladybrownPIDout = ladybrownPID.update(ladybrownPID_target - ladybrownRotationSensor.get_position());
        ladybrown.move_voltage(ladybrownPIDout);

		// standard wait 10 ms
		pros::delay(10);  
    }
}