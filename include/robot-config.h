using namespace vex;

extern brain Brain;
extern motor BackRightMotor;
extern motor_group RightDriveSmart;
extern motor BackLeftMotor;
extern motor_group LeftDriveSmart;
extern smartdrive Drivetrain;
extern controller Controller;
extern motor IntakeMotorLeft;
extern motor IntakeMotorRight;
extern motor_group IntakeMotorGroup;
extern inertial InertialSensor;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
