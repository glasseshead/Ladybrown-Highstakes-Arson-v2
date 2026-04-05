#include "objects.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// TODO: Configure your ports based on your robot.
std::int8_t LEFT_MG_0 = 0;
std::int8_t LEFT_MG_1 = 0;
std::int8_t LEFT_MG_2 = 0;

std::int8_t RIGHT_MG_0 = 0;
std::int8_t RIGHT_MG_1 = 0;
std::int8_t RIGHT_MG_2 = 0;

std::int8_t INTAKE_MOTOR = 0;
std::int8_t LADYBROWN_MOTOR_LEFT = 0;
std::int8_t LADYBROWN_MOTOR_RIGHT = 0;

std::int8_t VISION_SENSOR = 0;
std::int8_t LADYBROWN_ROTATION_SENSOR = 0;
std::int8_t IMU_SENSOR = 0;

char MOGOCLAMP_PISTON = 'A';
char HANG_PISTON = 'A';
char DOINKER_PISTON = 'A';
char CLIMB_PISTONS = 'A';
char COLORSORT_PISTON = 'A';

// TODO: Configure your controls to your preference.
// Original Controls:
// intakeControl = pros::E_CONTROLLER_DIGITAL_L1;
// outtakeControl = pros::E_CONTROLLER_DIGITAL_L2;
// ladybrownControl = pros::E_CONTROLLER_DIGITAL_R1;
// MogoClampControl = pros::E_CONTROLLER_DIGITAL_R2;
// doinkerControl = pros::E_CONTROLLER_DIGITAL_DOWN;
// climbControl = pros::E_CONTROLLER_DIGITAL_LEFT;

// controls mapping
pros::controller_digital_e_t intakeControl = pros::E_CONTROLLER_DIGITAL_L1;
pros::controller_digital_e_t outtakeControl = pros::E_CONTROLLER_DIGITAL_L2;
pros::controller_digital_e_t ladybrownControl = pros::E_CONTROLLER_DIGITAL_R1;
pros::controller_digital_e_t MogoClampControl = pros::E_CONTROLLER_DIGITAL_R2;
pros::controller_digital_e_t doinkerControl = pros::E_CONTROLLER_DIGITAL_DOWN;
pros::controller_digital_e_t climbControl = pros::E_CONTROLLER_DIGITAL_LEFT;

// TODO: Configure your colour signatures
int32_t REDSIG = 1;
int32_t BLUESIG = 1;

int32_t REDu_min = 0;
int32_t REDu_max = 0;
int32_t REDu_mean = 0;
int32_t REDv_min = 0;
int32_t REDv_max = 0;
int32_t REDv_mean = 0;
int32_t REDrange = 0;
int32_t REDtype = 0;

int32_t BLUEu_min = 0;
int32_t BLUEu_max = 0;
int32_t BLUEu_mean = 0;
int32_t BLUEv_min = 0;
int32_t BLUEv_max = 0;
int32_t BLUEv_mean = 0;
int32_t BLUErange = 0;
int32_t BLUEtype = 0;

// motor groups (3WD)
pros::MotorGroup left_mg({LEFT_MG_0, LEFT_MG_1, LEFT_MG_2}, pros::v5::MotorGears::blue);
pros::MotorGroup right_mg({RIGHT_MG_0, RIGHT_MG_1, RIGHT_MG_2}, pros::v5::MotorGears::blue);

// intake mapping
pros::Motor intake(INTAKE_MOTOR, pros::v5::MotorGears::blue);

// ladybrown motor group mapping
pros::MotorGroup ladybrown({LADYBROWN_MOTOR_LEFT, static_cast<std::int8_t>(-LADYBROWN_MOTOR_RIGHT)}, pros::v5::MotorGears::green);

// mogo clamp piston mapping
pros::adi::DigitalOut mogoClampPiston(MOGOCLAMP_PISTON);

// hang piston mapping
pros::adi::DigitalOut hangPiston(HANG_PISTON);

// doinker piston mapping
pros::adi::DigitalOut doinkerPiston(DOINKER_PISTON);

// climb pistons mapping
pros::adi::DigitalOut climbPistons(CLIMB_PISTONS);

// color sort chain piston mapping
pros::adi::DigitalOut colorSortPiston(COLORSORT_PISTON);

// imu mapping
pros::Imu imu(IMU_SENSOR);

pros::vision_signature_s_t redSignature =
    pros::Vision::signature_from_utility(REDSIG, REDu_min, REDu_max, REDu_mean, REDv_min, REDv_max, REDv_mean, REDrange, REDtype);

pros::vision_signature_s_t blueSignature =
    pros::Vision::signature_from_utility(BLUESIG, BLUEu_min, BLUEu_max, BLUEu_mean, BLUEv_min, BLUEv_max, BLUEv_mean, BLUErange, BLUEtype);

// in order for the code to recognize that it was defined, red is here as a dummy
pros::vision_signature_s_t teamColorSignature =
    pros::Vision::signature_from_utility(REDSIG, REDu_min, REDu_max, REDu_mean, REDv_min, REDv_max, REDv_mean, REDrange, REDtype);

// ladybrown rotation sensor mapping
pros::Rotation ladybrownRotationSensor (LADYBROWN_ROTATION_SENSOR);

// vision sensor mapping
pros::Vision vision (VISION_SENSOR);

void initVision() {
    vision.set_signature(REDSIG, &redSignature);
    vision.set_signature(BLUESIG, &blueSignature);
}

// TODO: Configure your drivetrain settings.
// drivetrain mapping
lemlib::Drivetrain drivetrain(&left_mg,
                              // left motor group

                              &right_mg, 
                              // right motor group

                              0,
                              // track width 

                              lemlib::Omniwheel::NEW_4,
                              // wheel type 

                              0, 
                              // drivetrain rpm

                              0
                              // horizontal drift
);

// TODO: Configure your lateral and angular controllers.
// tracking wheel mapping
lemlib::TrackingWheel vertical_tracking_wheel(
    &left_mg,
    // motor/encoder

    lemlib::Omniwheel::NEW_2,
    // wheel type

    0,
    // offset

    0
    // drivetrain rpm
);

// tracking wheel mapping
lemlib::TrackingWheel horizontal_tracking_wheel(
    &right_mg,
    // motor/encoder
    
    lemlib::Omniwheel::NEW_2,
    // wheel type
    
    0,
    // offset

    0
    // drivetrain rpm
);

// odom sensors
lemlib::OdomSensors sensors(&vertical_tracking_wheel, 
                            // vertical tracking wheel 1

                            nullptr, 
                            // vertical tracking wheel 2

                            &horizontal_tracking_wheel, 
                            // horizontal tracking wheel 1

                            nullptr, 
                            // horizontal tracking wheel 2

                            &imu 
                            // inertia sensor
);

// lateral controller settings
lemlib::ControllerSettings lateral_controller(2, 
                                              // proportional gain (kP)
                                              0, 
                                              // integral gain (kI)

                                              10, 
                                              // derivative gain (kD)

                                              0, 
                                              // antiwindup

                                              0, 
                                              // small error range (in)

                                              0, 
                                              // small error range timeout (ms)

                                              0, 
                                              // large error range (in)

                                              0, 
                                              // large error range timeout (ms)

                                              0 
                                              // maximum acceleration (slew)
);

// angular controller settings
lemlib::ControllerSettings angular_controller(2, 
                                              // proportional gain (kP)

                                              0, 
                                              // integral gain (kI)

                                              10, 
                                              // derivative gain (kD)

                                              3, 
                                              // anti windup

                                              1, 
                                              // small error range (degrees)

                                              100, 
                                              // small error range timeout (ms)

                                              3, 
                                              // large error range (degrees)

                                              500, 
                                              // large error range timeout (ms)

                                              0 
                                              // maximum acceleration (slew)
);

// chassis mapping
lemlib::Chassis chassis(drivetrain, 
                        // drivetrain

                        lateral_controller, 
                        // lateral PID

                        angular_controller, 
                        // angular PID

                        sensors 
                        // odom
);

// TODO: Tune your ladybrown PID and target positions
// reset output position for ladybrown pid output
float ladybrownPIDout = 0.00;

// ladybrown pid
lemlib::PID ladybrownPID(5,
                         // proportional gain (kP)
                         0.01,
                         // integral gain (kI)
                         20,
                         // derivative gain (kD)
                         5,
                         // antiwindup
                         false
                         // sign flip reset boolean
);

std::int32_t ladybrownPID_downTarget = 0;
std::int32_t ladybrownPID_upTarget = 0;
std::int32_t ladybrownPID_target = 0;