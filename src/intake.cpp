// TODO: Replace intakePressed with intakePressed_intaking & intakePressed_outtaking

#include "intake.hpp"

// reset intake values

// was intake toggled just now?
// no, so it is false
bool intakePressed_intaking = false;
bool intakePressed_outtaking = false
int intakeState = 0;

void updateIntake() {
    // state = 1: intake
    // state = 2: outtake
    // state = 0: off

    // if R1 is pressed
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        if (!intakePressed_intaking) {
            // if it is on turn it off
            if(intakeState == 1) {
                intakeState = 0;
            }

            // if it is off turn it on
            else {
                intakeState = 1;
            }
        }
        // intake was just toggled just now
        intakePressed_intaking = true;

    } 
    // intake was not toggled just now
    else {
        intakePressed_intaking = false;
    }

    // if R2 is pressed
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        if (!intakePressed_outtaking) {
            // if it is on turn it off
            if(intakeState == 2) {
                intakeState = 0;
            }
            
            // if it is off turn it on
            else {
                intakeState = 2;
            }
        }
        // intake was just toggled just now
        intakePressed_outtaking = true;
        
    }
    // intake was not toggled just now
    else {
        intakePressed_outtaking = false;
    }
}

void runIntake() {
    while (true) {
        // based on our intake state, we toggle it on or off
        switch (intakeState) {
            // intaking
            case 1:
                intake.move_voltage(127);
                storage.move_voltage(127);
            // outtaking
            case 2:
                intake.move_voltage(-127);
                storage.move_voltage(-127);
            // off
            case 0:
                intake.move_voltage(0);
        }
    }
}