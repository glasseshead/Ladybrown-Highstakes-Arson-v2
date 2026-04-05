#include "lemlib/api.hpp" // IWYU pragma: keep
#include "intake.hpp"
#include "mogoclamp.hpp"
#include "ladybrown.hpp"
#include "climb.hpp"
#include "color.hpp"
#include "tasks.hpp"

void initTasks() {
    pros::Task intakeTask(runIntake, "intake/outtake task");
    pros::Task mogoClampTask(runMogoClamp, "mogo clamp task");
    pros::Task ladybrownTask(runLadybrown, "ladybrown task");
    pros::Task climbTask(runClimb, "climb task");
    pros::Task checkColorTask(checkColor, "check color task");
}