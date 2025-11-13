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
double accel_raw = 0;
double turn = 0;
const double_t turnMultiplier = 1;
double headingDeg = 0;
double headingRad = 0;
double diff = 0;
double accel_out = 0;
bool facingBackwards = false;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void calibrateInertial() {
  InertialSensor.setHeading(0, deg);
  Drivetrain.setHeading(0, deg);
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    Brain.Screen.setCursor(1, 1);
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Calibrating Inertial... Do NOT move.");
    Brain.Screen.print("Calibrating Inertial... Do NOT move.");
    wait(100, msec);
  }
  Brain.Screen.clearScreen();
  Controller.Screen.clearLine();
}

void pre_auton(void) {
  vexcodeInit();

  // set brake modes & velocities
  BackLeftMotor.setBrake(brake);
  BackRightMotor.setBrake(brake);
  IntakeMotorGroup.setStopping(coast);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(100, percent);
  Drivetrain.setTimeout(3, seconds);
  IntakeMotorGroup.setVelocity(45, percent);



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

void telemetry(void) {
  Brain.Screen.setCursor(1, 1);
  Controller.Screen.setCursor(1, 1);
  Brain.Screen.print("Drivetrain Heading: %.2f", InertialSensor.heading());
  Controller.Screen.print("Heading: %.2f", InertialSensor.heading());
}

void autonomous(void) {
  calibrateInertial();

  // Telemetry loop
  while (true) {
    telemetry();
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
  while (1) {
 
    // Drive control
    headingDeg = InertialSensor.heading();
    diff = fabs(fmod(headingDeg - 180 + 360, 360) - 180);
    facingBackwards = (diff < 90);
    accel_raw = Controller.Axis3.position();
    turn = Controller.Axis1.position();
    accel_out = facingBackwards ? -accel_raw : accel_raw;
    Drivetrain.arcade(accel_out, turn * turnMultiplier);

    
    // Telemetry loop
    telemetry();

    // Inertial reset heading
    if (Controller.ButtonY.pressing()) {
      InertialSensor.resetHeading();
    }

    // Intake Control
    // fast intake for picking up
    if (Controller.ButtonL1.pressing()) {
      IntakeMotorGroup.setVelocity(85, percent);
      IntakeMotorGroup.spin(forward);
      // outtake max speed
    } else if (Controller.ButtonL2.pressing()) {
      IntakeMotorGroup.setVelocity(100, percent);
      IntakeMotorGroup.spin(reverse);
      // slow intake for scoring
    } else if(Controller.ButtonR1.pressing()) {
        IntakeMotorGroup.setVelocity(50, percent);
        IntakeMotorGroup.spin(forward);
      } else {
      IntakeMotorGroup.stop();
      IntakeMotorGroup.setVelocity(85, percent);
    }

    wait(20, msec);
    Brain.Screen.clearScreen();
    Controller.Screen.clearLine();
  }
}

int main() {
  // Run the pre-autonomous function.
  pre_auton();
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }

}