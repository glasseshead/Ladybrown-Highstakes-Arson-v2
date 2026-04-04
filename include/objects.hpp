#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/vision.hpp"

// intake & storage motor
extern pros::Motor intake;

// ladybrown arm motor
extern pros::Motor ladybrown_l;
extern pros::Motor ladybrown_r;

// drivetrain and chassis
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

// controller
extern pros::Controller controller;

// drive motor groups
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

// odom sensors
extern lemlib::OdomSensors sensors;

// lateral and angular controls
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;

// mogo clamp piston
extern pros::adi::DigitalOut mogoClampPiston;

// hang piston
extern pros::adi::DigitalOut hangPiston;

// doinker piston
extern pros::adi::DigitalOut doinkerPiston;

// climb pistons
extern pros::adi::DigitalOut climbPistons;

// vision sensor
extern pros::Vision vision;

// controls
extern pros::controller_digital_e_t intakeControl;
extern pros::controller_digital_e_t outtakeControl;
extern pros::controller_digital_e_t ladybrownControl;
extern pros::controller_digital_e_t MogoClampControl;
extern pros::controller_digital_e_t doinkerControl;
extern pros::controller_digital_e_t climbControl;

// drivetrain motor ports
extern std::int8_t LEFT_MG_0;
extern std::int8_t LEFT_MG_1;
extern std::int8_t LEFT_MG_2;

extern std::int8_t RIGHT_MG_0;
extern std::int8_t RIGHT_MG_1;
extern std::int8_t RIGHT_MG_2;

// intake & storage motor port
extern std::int8_t INTAKE_MOTOR;

// ladybrown motor port
extern std::int8_t LADYBROWN_MOTOR_LEFT;
extern std::int8_t LADYBROWN_MOTOR_RIGHT;

// mogo clamp piston port
extern char MOGOCLAMP_PISTON;

// hang piston port
extern char HANG_PISTON;

// doinker piston port
extern char DOINKER_PISTON;

// climb pistons port
extern char CLIMB_PISTONS;

// imu port
extern std::int8_t IMU;

// vision sensor port
extern std::int8_t VISION_SENSOR;

// intake motor voltage (for color sort)
extern std::int32_t INTAKE_VOLTAGE;

// vision sensor color signatures
extern pros::vision_signature_s_t redSignature;
extern pros::vision_signature_s_t blueSignature;
extern pros::vision_signature_s_t teamColorSignature;

extern int32_t REDSIG;
extern int32_t BLUESIG;

extern int32_t REDu_min;
extern int32_t REDu_max;
extern int32_t REDu_mean;
extern int32_t REDv_min;
extern int32_t REDv_max;
extern int32_t REDv_mean;
extern int32_t REDrange;
extern int32_t REDtype;

extern int32_t BLUEu_min;
extern int32_t BLUEu_max;
extern int32_t BLUEu_mean;
extern int32_t BLUEv_min;
extern int32_t BLUEv_max;
extern int32_t BLUEv_mean;
extern int32_t BLUErange;
extern int32_t BLUEtype;

// initializing initialize vision sensor for color
void initialize_vision();