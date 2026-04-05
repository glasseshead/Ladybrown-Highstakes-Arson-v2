#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "tasks.hpp"
#include "intake.hpp"
#include "ladybrown.hpp"
#include "mogoclamp.hpp"
#include "climb.hpp"
#include "color.hpp"


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {
		pros::lcd::set_text(2, "Center Button is Pressed");
	} 

	else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "arson, yaaay!");

	pros::lcd::register_btn1_cb(on_center_button);

	// initialize vision
	initVision();

	// reset ladybrown rotation sensor
	ladybrownRotationSensor.reset();
  	ladybrownRotationSensor.set_data_rate(5);

	// reset ladybrown pid
    ladybrownPID.reset();

	// initialize tasks
	initTasks();
}

void disabled() {

}

void competition_initialize() {
    // set detected to the largest "blob" of color detected
	pros::vision_object_s_t detected = vision.get_by_size(0);

	// to set up for color sort
    // if the signature is red, set the team color signature to red
    if (detected.signature == redSignature.id) {
        teamColorSignature = redSignature;
    }
    // if the signature is blue, set the team color signature to red
    else if (detected.signature == blueSignature.id) {
        teamColorSignature = blueSignature;
    }
}

void autonomous() {
}

void opcontrol() {
	while (true) {
		// for those who aren't familiar with aircraft controls:
		// throttle is forward power
		// rudder is your yaw/turn
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rudder = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // standard movement
        chassis.arcade(throttle, rudder);

		updateIntake();
		updateLadybrown();
		updateClimb();
		updateMogoClamp();

		// standard wait 10 ms
		pros::delay(10);  
	}
}