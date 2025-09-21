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


/* TODO: Get new cables
TODO: CHANGE BACK LEFT MOTOR 
TODO: CONFIRM MOTOR PORTS & DEFINITIONS

TODO: CONFIRM MOTOR INVERSIONS

*/
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
int32_t fwdVal = 0;
int32_t turnVal = 0;
const int DEADZONE = 5;
const int TURN_MULTIPLIER = 2/3;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}


void autonomous(void) {}

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

    if (abs(fwdVal) < DEADZONE) {
      fwdVal = 0;
    }
    if (abs(turnVal) < DEADZONE) {
      turnVal = 0;
    }

    fwdVal = Controller.Axis3.position();
    turnVal = Controller.Axis1.position() * TURN_MULTIPLIER;
    Drivetrain.arcade(fwdVal, turnVal);
    // Drivetrain.drive(forward);



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

// Main will set up the competition functions and callbacks.
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
