#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;


const distanceUnits DISTANCE_UNITS = mm;

const gearSetting DRIVETRAIN_MOTOR_GEAR_RATIO = ratio18_1;
// const double WHEEL_CIRCUMFERENCE = 3.25 * atan(1) * 4;
const double WHEEL_CIRCUMFERENCE = 355.6;

const double TRACKWIDTH = 368.3;
const double INTERNAL_GEAR_RATIO = 1;
const double WHEELBASE = 266.7;


//DRIVETRAIN PORT DEFINITIONS
const int32_t FRONT_RIGHT_MOTOR_PORT = 1;
const int32_t FRONT_LEFT_MOTOR_PORT = 2;
const int32_t BACK_RIGHT_MOTOR_PORT = 3;
const int32_t BACK_LEFT_MOTOR_PORT = 0;



//DRIVETRAIN INVERSIONS
const bool BACK_LEFT_MOTOR_INVERTED = true;
const bool BACK_RIGHT_MOTOR_INVERTED = false;
const bool FRONT_LEFT_MOTOR_INVERTED = true;
const bool FRONT_RIGHT_MOTOR_INVERTED = false;


// CREATING OBJECTS
motor backLeftMotor = motor( BACK_LEFT_MOTOR_PORT, BACK_LEFT_MOTOR_INVERTED );
motor frontLeftMotor = motor( FRONT_LEFT_MOTOR_PORT, FRONT_LEFT_MOTOR_INVERTED );
motor backRightMotor = motor( BACK_RIGHT_MOTOR_PORT, BACK_RIGHT_MOTOR_INVERTED );
motor frontRightMotor = motor( FRONT_RIGHT_MOTOR_PORT, FRONT_RIGHT_MOTOR_INVERTED );

motor_group leftDriveSmart = motor_group( backLeftMotor, frontLeftMotor );
motor_group rightDriveSmart = motor_group( backRightMotor, frontRightMotor );
drivetrain Drivetrain = drivetrain(leftDriveSmart, rightDriveSmart, WHEEL_CIRCUMFERENCE, TRACKWIDTH, WHEELBASE, DISTANCE_UNITS, INTERNAL_GEAR_RATIO );

controller Controller = controller();



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}