#include "color.hpp"

bool teamColorPressed_red = false;
bool teamColorPressed_blue = false;
int teamColorState = 0;

// reset team color state based on our preload is in main.cpp

void updateTeamColor() {
    // state = 0: team color toggle red
    // state = 1: team color toggle blue

    // if team color toggle control is pressed
    if (controller.get_digital(teamColorControl_Red)) {
        if (!teamColorPressed_red) {
                teamColorState = 0;
        }
        // team color toggle red was just toggled just now
        teamColorPressed_red = true;

    } 
    // team color toggle red was not toggled just now
    else {
        teamColorPressed_red = false;
    }

    // if R2 is pressed
    if (controller.get_digital(teamColorControl_Blue)) {
        if (!teamColorPressed_blue) {
                teamColorState = 1;
            }
        // team color toggle blue was just toggled just now
        teamColorPressed_blue = true;
        
    }
    // team color toggle blue was not toggled just now
    else {
        teamColorPressed_blue = false;
    }
}

void runColor() {
    while (true) {
        // based on our team color state, we toggle it red or blue for detection
        switch (teamColorState) {
            // setting color sort to sort for red
            case 0:
                teamColorSignature = redSignature;
            // setting color sort to sort for blue
            case 1:
                teamColorSignature = blueSignature;
        }
    }
}

void checkColor() {
    // set detected to the largest "blob" of color detected
    pros::vision_object_s_t detected = vision.get_by_size(0);

    // if the signature is your team color, retract piston to allow it to flip down

    // TODO: Please pick one configuration for the bot. By default, this is colorSortPiston.
    if (detected.signature == teamColorSignature.id) {
        while (COLORSORT_DISTANCE_MIN < colorDistance.get() < COLORSORT_DISTANCE_MAX) {
            // outtake has nothing for this, it runs as normal
            
            // ladybrown
            
            /*
            std::int32_t ladybrownPID_target = ladybrownPID_downTarget;
            float ladybrownPIDout = ladybrownPID.update(ladybrownPID_target - ladybrownRotationSensor.get_position());
            ladybrown.move_voltage(ladybrownPIDout);
            */

            // color sort piston
            colorSortPiston.set_value(false);
        }
    }
    // if the signature is not your team color, extend piston to throw it out
    else {
        // outtake
        
        /*
        intake.move_relative(360, 100);
        while (abs(intake.get_position()-360) > 10) {
            pros::delay(10);
        }
        */
            
        // ladybrown
        
        std::int32_t ladybrownPID_target = ladybrownPID_colorTarget;
        float ladybrownPIDout = ladybrownPID.update(ladybrownPID_target - ladybrownRotationSensor.get_position());
        ladybrown.move_voltage(ladybrownPIDout);
        
        
        // color sort piston
        colorSortPiston.set_value(true);
    }
}