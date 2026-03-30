#include "objects.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

std::int8_t LEFT_MG_0 = 0;
std::int8_t LEFT_MG_1 = 0;
std::int8_t LEFT_MG_2 = 0;

std::int8_t RIGHT_MG_0 = 0;
std::int8_t RIGHT_MG_1 = 0;
std::int8_t RIGHT_MG_2 = 0;

std::int8_t INTAKE_MOTOR = 0;
std::int8_t LADYBROWN_MOTOR_LEFT = 0;
std::int8_t LADYBROWN_MOTOR_RIGHT = 0;

char MOGOCLAMP_PISTON = 'A';
char HANG_PISTON = 'A';
char DOINKER_PISTON = 'A';

std::int8_t IMU_SENSOR = 0;

// TODO: Configure your controls to your preference.
// Original Controls:
// TODO: write these you bum

// controls mapping
pros::controller_digital_e_t scoreControl = pros::E_CONTROLLER_DIGITAL_L1;

// motor groups (3WD)
pros::MotorGroup left_mg({LEFT_MG_0, LEFT_MG_1, LEFT_MG_2}, pros::v5::MotorGears::blue);
pros::MotorGroup right_mg({RIGHT_MG_0, RIGHT_MG_1, RIGHT_MG_2}, pros::v5::MotorGears::blue);

// intake mapping
pros::Motor intake(INTAKE_MOTOR, pros::v5::MotorGears::blue);

// ladybrown mapping
pros::Motor ladybrown_l(LADYBROWN_MOTOR_LEFT, pros::v5::MotorGears::green);
pros::Motor ladybrown_r(LADYBROWN_MOTOR_RIGHT, pros::v5::MotorGears::green);

// mogo clamp piston mapping
pros::adi::DigitalOut mogoClampPiston(MOGOCLAMP_PISTON);

// hang piston mapping
pros::adi::DigitalOut hangPiston(HANG_PISTON);

// doinker piston mapping
pros::adi::DigitalOut doinkerPiston(DOINKER_PISTON);

// imu mapping
pros::Imu imu(IMU_SENSOR);

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
