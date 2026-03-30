#include "lemlib/api.hpp" // IWYU pragma: keep
#include "intake.hpp"
#include "descore.hpp"
#include "mogo clamp.hpp"
#include "midgoal.hpp"
#include "score.hpp"
#include "trapdoor.hpp"
#include "tasks.hpp"

void initTasks() {
    pros::Task intakeTask(runIntake, "intake/outtake task");
    pros::Task scoreTask(runScore, "score task");
    pros::Task descoreTask(runDescore, "descore wing task");
    pros::Task mogoClampTask(runMatchLoader, "mogo clamp task");
    pros::Task midGoalTask(runMidGoal, "mid goal task");
    pros::Task trapdoorTask(runTrapdoor, "trapdoor task");
}