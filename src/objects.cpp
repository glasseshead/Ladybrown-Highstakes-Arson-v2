#include "objects.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup left_mg({0, 0, 0}, pros::v5::MotorGears::blue);
pros::MotorGroup right_mg({0, 0, 0}, pros::v5::MotorGears::blue);

// intake mapping
pros::Motor intake(0, pros::v5::MotorGears::blue);

// storage mapping
pros::Motor storage(0, pros::v5::MotorGears::blue);

// score mapping
pros::Motor score(0, pros::v5::MotorGears::blue);

// descore piston mapping
pros::ADIAnalogOut descorePiston ('A');

// mid goal piston mapping
pros::ADIAnalogOut midGoalPiston ('A');

// matchloader piston mapping
pros::ADIAnalogOut matchloader_L ('A');
pros::ADIAnalogOut matchloader_R ('A');

// imu mapping
pros::Imu imu(1);

// drivetrain mapping
lemlib::Drivetrain drivetrain(&left_mg,
                              // left motor group

                              &right_mg, 
                              // right motor group

                              10,
                              // track width 

                              lemlib::Omniwheel::NEW_4,
                              // wheel type 

                              360, 
                              // drivetrain rpm

                              2 
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

    360
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

    360
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
lemlib::ControllerSettings lateral_controller(10, 
                                              // proportional gain (kP)
                                              0, 
                                              // integral gain (kI)

                                              3, 
                                              // derivative gain (kD)

                                              3, 
                                              // antiwindup

                                              1, 
                                              // small error range (in)

                                              100, 
                                              // small error range timeout (ms)

                                              3, 
                                              // large error range (in)

                                              500, 
                                              // large error range timeout (ms)

                                              20 
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
