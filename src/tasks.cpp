#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "intake.hpp"
#include "descore.hpp"

void initTasks() {
    pros::Task intakeTask(runIntake, "intake/outtake task");
    pros::Task intakeTask(runScore, "score task");
    pros::Task descoreTask(runDescore, "descore wing task");
}