#include "ladybrown.hpp"

// reset ladybrown values

// was ladybrown toggled just now?
// no, so it is false
bool ladybrownPressed_intaking = false;
bool ladybrownPressed_outtaking = false;
int ladybrownState = 0;

void updateLadybrown() {
    // state = 0: ladybrown stop
    // state = 1: ladybrown score
    // state = 2: ladybrown unscore

    // if ladybrown control is pressed
    if (controller.get_digital(ladybrownControl)) {
        if (!ladybrownPressed_intaking) {
            // if it is scoring turn it to unscore
            if(ladybrownState == 1) {
                ladybrownState = 2;
            }
            // if it is unscoring turn it off
            if(ladybrownState == 2) {
                ladybrownState = 0;
            }
            // if it is off turn it to scoring
            if(ladybrownState == 0) {
                ladybrownState = 1;
            }
/*
            // if it is off turn it score
            else {
                ladybrownState = 1;
*/
        }
        // ladybrown was just toggled just now
        ladybrownPressed_intaking = true;
    }
    // ladybrown was not toggled just now
    else {
        ladybrownPressed_intaking = false;
    }
}

// TODO: Check if it's fine for me to use a motor group
void runLadybrown() {
    while (true) {
        // based on our ladybrown state, we toggle it on or off
        switch (ladybrownState) {
            // ladybrown off 
            case 0:
                ladybrown_l.move_voltage(0);
                ladybrown_r.move_voltage(0);

            // ladybrown scoring
            case 1:
                ladybrown_l.move_voltage(200);
                ladybrown_r.move_voltage(200);

            // ladybrown unscoring
            case 2:
                ladybrown_l.move_voltage(-200);
                ladybrown_r.move_voltage(-200);

        }
    }
}