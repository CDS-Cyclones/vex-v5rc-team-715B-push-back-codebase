/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
double accel = 0;
double turn = 0;
const double_t turnMultiplier = 0.5;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  BackLeftMotor.setBrake(brake);
  BackRightMotor.setBrake(brake);
  IntakeMotorGroup.setStopping(coast);
  Drivetrain.setTurnVelocity(200, rpm);
  InertialSensor.calibrate(2);
  while(InertialSensor.isCalibrating()) {
   Brain.Screen.print("Calibrating Inertial, DO NOT MOVE");
    wait(2000, msec);
  }
  Brain.Screen.clearScreen();


  //TODO: see if this works lmao, if not just set it in the spinning command.
  // 45 percent, ~5 watts 
  IntakeMotorGroup.setVelocity(45, percent);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
Drivetrain.turnFor(turnType::right, 180, rotationUnits::deg, 100, rpm, true);
    while(1) {
    Brain.Screen.setCursor(1,1);
      Brain.Screen.print("Autonomous Running");
      Brain.Screen.setCursor(3,1);
    Brain.Screen.print("Drivetrain Heading: %.2f", InertialSensor.heading());
    wait(100, msec);
    Brain.Screen.clearScreen();
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {



    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Drivetrain Heading: %.2f", InertialSensor.heading());
    accel = Controller.Axis1.position();
    turn = Controller.Axis3.position();
    Drivetrain.arcade(accel, turn * turnMultiplier);




    if(Controller.ButtonL1.pressing()) {
      IntakeMotorGroup.setVelocity(45, percent);
      IntakeMotorGroup.spin(forward);
    } else if(Controller.ButtonL2.pressing()) {
      IntakeMotorGroup.setVelocity(100, percent);
      IntakeMotorGroup.spin(reverse);
    } else {
      IntakeMotorGroup.stop();
      IntakeMotorGroup.setVelocity(45, percent);
    }



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
    Brain.Screen.clearScreen();
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
