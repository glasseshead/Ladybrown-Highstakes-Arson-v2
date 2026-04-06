#pragma once
#include "main.h"
#include "objects.hpp"

// declaring detected color sensor variable and team color state
extern pros::vision_object_s_t detected;
extern int teamColorState;

// initializing check function for color
void updateTeamColor();
void runColor();
void checkColor();