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
const int32_t BACK_RIGHT_MOTOR_PORT = PORT12;
const bool BACK_RIGHT_MOTOR_REVERSED = true;
motor BackRightMotor = motor( BACK_RIGHT_MOTOR_PORT, BACK_RIGHT_MOTOR_REVERSED );

//Left side declarations
const int32_t BACK_LEFT_MOTOR_PORT = PORT11;
const bool BACK_LEFT_MOTOR_REVERSED = false;
motor BackLeftMotor = motor( BACK_LEFT_MOTOR_PORT, BACK_LEFT_MOTOR_REVERSED );


// Intake Motor declarations
const int32_t INTAKE_MOTOR_PORT_LEFT = PORT9;
const bool INTAKE_MOTOR_REVERSED_LEFT = false;

const int32_t INTAKE_MOTOR_PORT_RIGHT = PORT10;
const bool INTAKE_MOTOR_REVERSED_RIGHT = false;

motor IntakeMotorLeft = motor( INTAKE_MOTOR_PORT_LEFT, INTAKE_MOTOR_REVERSED_LEFT );
motor IntakeMotorRight = motor( INTAKE_MOTOR_PORT_RIGHT, INTAKE_MOTOR_REVERSED_RIGHT );

motor_group IntakeMotorGroup = motor_group( IntakeMotorLeft, IntakeMotorRight );


// misc. definitions
// drivetrain Drivetrain = drivetrain(BackLeftMotor, BackRightMotor, WHEEL_CIRCUMFERENCE, TRACKWIDTH, WHEELBASE, DISTANCE_UNITS, INTERNAL_GEAR_RATIO);
inertial InertialSensor = inertial( PORT1 );
smartdrive Drivetrain = smartdrive(BackLeftMotor,BackRightMotor,InertialSensor, WHEEL_CIRCUMFERENCE, TRACKWIDTH, WHEELBASE, DISTANCE_UNITS, INTERNAL_GEAR_RATIO);
controller Controller = controller();

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}