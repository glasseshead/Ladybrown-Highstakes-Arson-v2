#include "objects.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// TODO: Configure your ports based on your robot.
std::int8_t LEFT_MG_0 = 0;
std::int8_t LEFT_MG_1 = 0;
std::int8_t LEFT_MG_2 = 0;
std::int8_t LEFT_MG_3 = 0;

std::int8_t RIGHT_MG_0 = 0;
std::int8_t RIGHT_MG_1 = 0;
std::int8_t RIGHT_MG_2 = 0;
std::int8_t RIGHT_MG_3 = 0;

std::int8_t INTAKE_MOTOR = 0;
std::int8_t SCORE_MOTOR = 0;

char DESCORE_PISTON = 'A';
char MID_GOAL_PISTON = 'A';
char TRAPDOOR_PISTON = 'A';
char MATCHLOADER_PISTON_L = 'A';
char MATCHLOADER_PISTON_R = 'A';

std::int8_t IMU_SENSOR = 0;

// TODO: Configure your controls to your preference.
// Original Controls:
// scoreControl = pros::E_CONTROLLER_DIGITAL_L1;
// outtakeControl = pros::E_CONTROLLER_DIGITAL_L2;
// intakeControl = pros::E_CONTROLLER_DIGITAL_R1;
// descoreControl = pros::E_CONTROLLER_DIGITAL_R2;
// matchloaderControl = pros::E_CONTROLLER_DIGITAL_DOWN;
// midGoalControl = pros::E_CONTROLLER_DIGITAL_RIGHT;

// controls mapping
pros::controller_digital_e_t scoreControl = pros::E_CONTROLLER_DIGITAL_L1;
pros::controller_digital_e_t outtakeControl = pros::E_CONTROLLER_DIGITAL_L2;
pros::controller_digital_e_t intakeControl = pros::E_CONTROLLER_DIGITAL_R1;
pros::controller_digital_e_t descoreControl = pros::E_CONTROLLER_DIGITAL_R2;
pros::controller_digital_e_t matchloaderControl = pros::E_CONTROLLER_DIGITAL_DOWN;
pros::controller_digital_e_t midGoalControl = pros::E_CONTROLLER_DIGITAL_RIGHT;



// motor groups
pros::MotorGroup left_mg({LEFT_MG_0, LEFT_MG_1, LEFT_MG_2}, pros::v5::MotorGears::blue);
pros::MotorGroup right_mg({RIGHT_MG_0, RIGHT_MG_1, RIGHT_MG_3}, pros::v5::MotorGears::blue);

// intake mapping
pros::Motor intake(INTAKE_MOTOR, pros::v5::MotorGears::blue);

// score mapping
pros::Motor score(SCORE_MOTOR, pros::v5::MotorGears::blue);

// descore piston mapping
pros::adi::AnalogOut descorePiston (DESCORE_PISTON);

// mid goal piston mapping
pros::adi::AnalogOut midGoalPiston (MID_GOAL_PISTON);

// trapdoor piston mapping
pros::adi::AnalogOut trapdoorPiston (TRAPDOOR_PISTON);

// matchloader piston mapping
pros::adi::AnalogOut matchLoaderPiston_L (MATCHLOADER_PISTON_L);
pros::adi::AnalogOut matchLoaderPiston_R (MATCHLOADER_PISTON_R);

// imu mapping
pros::Imu imu(IMU_SENSOR);

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

// TODO: Configure your tracking wheel settings.
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

// TODO: Configure your lateral and angular controllers.
// lateral controller settings
lemlib::ControllerSettings lateral_controller(0, 
                                              // proportional gain (kP)
                                              0, 
                                              // integral gain (kI)

                                              0, 
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
lemlib::ControllerSettings angular_controller(0, 
                                              // proportional gain (kP)

                                              0, 
                                              // integral gain (kI)

                                              0, 
                                              // derivative gain (kD)

                                              0, 
                                              // anti windup

                                              0, 
                                              // small error range (degrees)

                                              0, 
                                              // small error range timeout (ms)

                                              0, 
                                              // large error range (degrees)

                                              0, 
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
