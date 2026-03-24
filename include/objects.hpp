#pragma once

#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"

// intake motor
extern pros::Motor intake;

// storage motor
extern pros::Motor storage;

// score motor
extern pros::Motor score;

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

// descore piston
extern pros::adi::AnalogOut descorePiston;

// mid goal piston
extern pros::adi::AnalogOut midGoalPiston;

// matchloader pistons
extern pros::adi::AnalogOut matchLoaderPiston_L;
extern pros::adi::AnalogOut matchLoaderPiston_R;

// controls
extern pros::controller_digital_e_t scoreControl;
extern pros::controller_digital_e_t outtakeControl;
extern pros::controller_digital_e_t intakeControl;
extern pros::controller_digital_e_t descoreControl;
extern pros::controller_digital_e_t matchloaderControl;
extern pros::controller_digital_e_t midGoalControl;