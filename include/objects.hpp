#pragma once

#include "main.h"
#include "lemlib/api.hpp"

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
extern pros::ADIAnalogOut descorePiston;

// mid goal piston
extern pros::ADIAnalogOut midGoalPiston;