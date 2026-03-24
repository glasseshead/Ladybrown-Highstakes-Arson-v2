#include "lemlib/api.hpp" // IWYU pragma: keep
#include "intake.hpp"
#include "descore.hpp"
#include "matchloader.hpp"
#include "midgoal.hpp"
#include "score.hpp"
#include "tasks.hpp"

void initTasks() {
    pros::Task intakeTask(runIntake, "intake/outtake task");
    pros::Task scoreTask(runScore, "score task");
    pros::Task descoreTask(runDescore, "descore wing task");
    pros::Task matchLoaderTask(runMatchLoader, "matchloader task");
    pros::Task midGoalTask(runMidGoal, "mid goal task");
}