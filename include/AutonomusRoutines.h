#include "tilter.h"

void autoScore(){
  myBase.Spin(-30, -30);
  myTilter.Spin(-60);
  myIntake.Spin(-50);
}

void score(){
  tilt1.resetRotation() ;
  tilt1.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
  tilt2.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);    

  while(tilt1.rotation(vex::rotationUnits::deg)<525 ){
    if(tilt1.rotation(vex::rotationUnits::deg)>200){
    tilt1.spin(vex::directionType::fwd,30,vex::velocityUnits::pct);
    tilt2.spin(vex::directionType::fwd,30,vex::velocityUnits::pct);  
    }
    vex::task::sleep(1) ;
  }
  vex::task::sleep(1500) ;
  autoScore();
  vex::task::sleep(2000) ;
}

void blueAuton(){
//Intake and drive forward 4 cubes
  myTilter.robotDeploy();
  myIntake.Spin(100);
  vex::task::sleep(100); 
  //myBase.driveInches_Enc(forwards, 50, 45);
  myBase.drivePID(50, 50, 47);//55
  vex::task::sleep(100);
  //myBase.drivePID(-45, -45, -10);
  myBase.driveInches_Enc(backwards, -7, 80);
  //myBase.drivePID(-40, -40, -20);

  //Turn towards right stack
  baseGyroReset;
  vex::task::sleep(500);
  while(Gyro.isCalibrating()){vex::task::sleep(1);}
  myBase.turnPID(50,50, 65);  //450 Gyro units is about 90 degrees

  //myBase.turnPID(50,50, 450);  //450 Gyro units is about 90 degrees
    
  //Drive into stack to intake first cube
  myBase.drivePID(50, 50, 14);
  vex::task::sleep(250);
  myBase.driveInches_Enc(backwards, -30, 80);      

  baseGyroReset;
  vex::task::sleep(500);
  while(Gyro.isCalibrating()){vex::task::sleep(1);}
  myBase.turnPID(50,50, -1050);  //450 Gyro units is about 90 degrees
  myBase.drivePID(50, 50, 15);
  myIntake.Stop();
  rightIntake.startRotateFor(-380,vex::rotationUnits::deg,80,vex::velocityUnits::pct);  
  leftIntake.rotateFor(-380,vex::rotationUnits::deg,80,vex::velocityUnits::pct); 
  vex::task::sleep(250);  
  score();  
}

void redAuton(){
  //Intake and drive forward 4 cubes
  myTilter.robotDeploy();
  myIntake.Spin(100);
  vex::task::sleep(100); 
  //myBase.driveInches_Enc(forwards, 50, 45);
  myBase.drivePID(50, 50, 47);//55
  vex::task::sleep(100);
  //myBase.drivePID(-45, -45, -10);
  myBase.driveInches_Enc(backwards, -7, 80);
  //myBase.drivePID(-40, -40, -20);

  //Turn towards right stack
  baseGyroReset;
  vex::task::sleep(500);
  while(Gyro.isCalibrating()){vex::task::sleep(1);}
  myBase.turnPID(50,50, -65);  //450 Gyro units is about 90 degrees

  //myBase.turnPID(50,50, 450);  //450 Gyro units is about 90 degrees
    
  //Drive into stack to intake first cube
  myBase.drivePID(50, 50, 16);
  vex::task::sleep(250);
  myBase.driveInches_Enc(backwards, -30, 80);      

  baseGyroReset;
  vex::task::sleep(500);
  while(Gyro.isCalibrating()){vex::task::sleep(1);}
  myBase.turnPID(50,50, 1050);  //450 Gyro units is about 90 degrees
  myBase.drivePID(50, 50, 15);
  myIntake.Stop();
  rightIntake.startRotateFor(-380,vex::rotationUnits::deg,80,vex::velocityUnits::pct);  
  leftIntake.rotateFor(-380,vex::rotationUnits::deg,80,vex::velocityUnits::pct); 
  vex::task::sleep(250);  
  score();  
}


//BLUE AUTON OLDDD
//first part is to calibrate gyro for turning
  /*Gyro.startCalibration();
  while(Gyro.isCalibrating())
        vex::task::sleep(1); 
    
    //after calibration turn slide on.
  deployslide(90,430) ;
  //after the slide deploys reverse back into the wall to align cubes.and drive train.
  
  
  //turn on the intake motors to prepare scoring cubes
  leftIntake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  rightIntake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  drivefwd_nopid(85,1520) ;//first paremeter is speed next parameter is distance.
  vex::task::sleep(1000) ; 
  //made to get the green cube to the right of things.
  reversedrive(100,400) ;
  turn_(8.5,false,80) ; //this will turn robot toe right using the gyro sensor.
  vex::task::sleep(100) ;
  drivefwd_nopid(120,420) ;
  vex::task::sleep(300) ;
  
  //turn intake motors to hold.
  //reversed
  
  //drive(180,670) ; //reverse back to the goal
  turn_(165,true,50) ;
  
  vex::task::sleep(50) ; //sleep system after turn for better accuracy
  drivefwd_nopid(160,370) ; //driveto the goal
  outake(300); ///get the last cube to the bottom to score all the cubes.
  score() ;//use the score function when cubes are ready to be delivered.*/


  //RED AUTON OLDDD
  /*//first part is to calibrate gyro for turning
  Gyro.startCalibration();
  while(Gyro.isCalibrating())
        vex::task::sleep(1); 
    
    //after calibration turn slide on.
  deployslide(90,430) ;
  //after the slide deploys reverse back into the wall to align cubes.and drive train.
  turn_(0.5,true,5) ;
  
  //turn on the intake motors to prepare scoring cubes
  leftIntake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  rightIntake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  drivefwd_nopid(85,1520) ;
  vex::task::sleep(1000) ; 
  //made to get the green cube to the right of things.
  reversedrive(100,400) ;
  turn_(9,true,80) ; //this will turn robot toe right using the gyro sensor.
  vex::task::sleep(100) ;
  drivefwd_nopid(120,350) ;
  vex::task::sleep(300) ;
  
  //turn intake motors to hold.
  reversedrive(180,650) ; //reverse back to the goal
  turn_(164.5,false,50) ;
  
  vex::task::sleep(50) ; //sleep system after turn for better accuracy
  drivefwd_nopid(160,385) ; //driveto the goal
  outake(300); ///get the last cube to the bottom to score all the cubes.
  score() ;//use the score function when cubes are ready to be delivered.*/