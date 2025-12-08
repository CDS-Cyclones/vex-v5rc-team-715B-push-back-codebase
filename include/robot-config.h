using namespace vex;

extern brain Brain;
extern motor_group RightMotorGroup;
extern motor_group LeftMotorGroup;
extern smartdrive Drivetrain;
extern controller Controller;
extern motor IntakeMotorLeft;
extern motor IntakeMotorRight;
extern motor_group IntakeMotorGroup;
extern inertial InertialSensor;
extern motor BackRightMotor;
extern motor BackLeftMotor;
extern motor FrontRightMotor;
extern motor FrontLeftMotor;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
