#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;


const distanceUnits DISTANCE_UNITS = mm;

const gearSetting DRIVETRAIN_MOTOR_GEAR_RATIO = ratio18_1;
const double WHEEL_CIRCUMFERENCE = 3.25 * atan(1) * 4;
const double TRACKWIDTH = 368.3;
const double INTERNAL_GEAR_RATIO = 1;
const double WHEELBASE = 266.7;


//Right side declarations
const int32_t FRONT_RIGHT_MOTOR_PORT = PORT1;
const int32_t BACK_RIGHT_MOTOR_PORT = PORT2;
const bool FRONT_RIGHT_MOTOR_REVERSED = true;
const bool BACK_RIGHT_MOTOR_REVERSED = true;
motor FrontRightMotor = motor( FRONT_RIGHT_MOTOR_PORT, FRONT_RIGHT_MOTOR_REVERSED );
motor BackRightMotor = motor( BACK_RIGHT_MOTOR_PORT, BACK_RIGHT_MOTOR_REVERSED );
motor_group RightDriveSmart = motor_group( FrontRightMotor, BackRightMotor );

//Left side declarations
const int32_t FRONT_LEFT_MOTOR_PORT = PORT3;
const int32_t BACK_LEFT_MOTOR_PORT = PORT4;
const bool FRONT_LEFT_MOTOR_REVERSED = false;
const bool BACK_LEFT_MOTOR_REVERSED = false;
motor FrontLeftMotor = motor( FRONT_LEFT_MOTOR_PORT, FRONT_LEFT_MOTOR_REVERSED );
motor BackLeftMotor = motor( BACK_LEFT_MOTOR_PORT, BACK_LEFT_MOTOR_REVERSED );
motor_group LeftDriveSmart = motor_group( FrontLeftMotor, BackLeftMotor );



drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, WHEEL_CIRCUMFERENCE, TRACKWIDTH, WHEELBASE, DISTANCE_UNITS, INTERNAL_GEAR_RATIO);
controller Controller = controller();

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}