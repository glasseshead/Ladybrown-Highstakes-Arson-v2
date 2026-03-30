#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

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

// controls
extern pros::controller_digital_e_t intakeControl;
extern pros::controller_digital_e_t outtakeControl;
extern pros::controller_digital_e_t ladybrownControl;
extern pros::controller_digital_e_t MogoClampControl;
extern pros::controller_digital_e_t doinkerControl;

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

// imu port
extern std::int8_t IMU;