#include "base.h"

class intake{
  private:
    int inSpeed = -300;
    int outSpeed = 300;
    int slowSpeed = 20;
  public:
    intake();
    void Spin(int speed);
    void Stop();
    void userControl();
};

intake::intake(){}

void intake::Spin(int speed){
  leftIntake.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  rightIntake.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}
void intake::Stop(){
  leftIntake.stop(vex::brakeType::brake);  
  rightIntake.stop(vex::brakeType::brake);  
}

void intake::userControl(){
  if(intakeBtn && outtakeBtn){
    this->Spin(this->slowSpeed);
  }else if(intakeBtn){ 
    this->Spin(this->inSpeed);
  }else if(outtakeBtn){ 
    this->Spin(this->outSpeed);
  }else if(autoScoreBtn){
    this->Spin(-50);
  }else{
    this->Stop();
  }
}




void outake(int distance ){
  //first reset encoder for outaking.
  rightIntake.resetRotation() ;
  leftIntake.spin(vex::directionType::rev, 70, vex::velocityUnits::pct);
  rightIntake.spin(vex::directionType::rev, 70, vex::velocityUnits::pct);
  while((rightIntake.rotation(vex::rotationUnits::deg)*-1)<distance) {
    vex::task::sleep(1) ;
  }
  leftIntake.stop(vex::brakeType::hold);
   rightIntake.stop(vex::brakeType::hold) ;
}



intake myIntake;