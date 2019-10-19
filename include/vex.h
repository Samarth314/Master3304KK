/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>

#include "v5.h"
#include "v5_vcs.h"
#include "vex_global.h"
#include "vex_units.h"

vex::brain       Brain;
// A global instance of vex::competition

// define your global instances of motors and other devices here
vex::motor LF = vex::motor( vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor LB = vex::motor( vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor RF = vex::motor( vex::PORT6, vex::gearSetting::ratio18_1, true);
vex::motor RB = vex::motor( vex::PORT20, vex::gearSetting::ratio18_1, true);

vex::motor leftIntake  = vex::motor( vex::PORT8, true );
vex::motor rightIntake = vex::motor( vex::PORT10, false);

vex::motor tilt1  = vex::motor( vex::PORT16, true); //left side
vex::motor tilt2  = vex::motor( vex::PORT19, false); // right side

vex::controller Controller1 = vex::controller();

vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.A);
vex::encoder leftEncoder  = vex::encoder(Brain.ThreeWirePort.E) ;
vex::encoder rightEncoder = vex::encoder(Brain.ThreeWirePort.G) ;
vex::bumper Bumper = vex::bumper(Brain.ThreeWirePort.B);

const double wheelDiameterIN  = 4.0; 
const double baseDiameterIN  = 15.0;

//Controller Buttons
#define Y_leftJoy Controller1.Axis3.value()
#define Y_rightJoy Controller1.Axis2.value()

#define X_leftJoy Controller1.Axis4.value()
#define X_rightJoy Controller1.Axis1.value()

#define btnX Controller1.ButtonX.pressing()
#define autoScoreBtn Controller1.ButtonA.pressing()
#define baseLockBtn Controller1.ButtonB.pressing()
#define btnY Controller1.ButtonY.pressing()

#define btnUp Controller1.ButtonUp.pressing()
#define btnRight Controller1.ButtonRight.pressing()
#define btnDown Controller1.ButtonDown.pressing()
#define btnLeft Controller1.ButtonLeft.pressing()

#define tiltOutBtn Controller1.ButtonL1.pressing()
#define tiltInBtn  Controller1.ButtonL2.pressing()

#define intakeBtn Controller1.ButtonR1.pressing()
#define outtakeBtn Controller1.ButtonR2.pressing()

//Sensors:
#define baseGyro (-Gyro.value(vex::analogUnits::mV))
#define baseGyroReset Gyro.startCalibration(1000)
#define leftBaseEnc leftEncoder.rotation(vex::rotationUnits::deg)
#define rightBaseEnc rightEncoder.rotation(vex::rotationUnits::deg)
#define leftBaseEncReset leftEncoder.resetRotation()
#define rightBaseEncReset rightEncoder.resetRotation()
#define tiltBumpBtn Bumper.pressing()