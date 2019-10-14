#include "intake.h"

enum tiltType {extend, retract};

class tilter{
  private:
    int inSpeed = 100;
    int outSpeed = -100;
    int slowSpeed = -12;
    void buttonReset();
  public:
    tilter();
    void Spin(int speed);
    void moveFor(double degToRotate, int speed);
    void Stop(bool type);
    void autoScore();         
    void userControl(); 
    void robotDeploy();  
    void autoScoreStack();
};

tilter::tilter(){}

void tilter::Spin(int speed){
  tilt1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);   
  tilt2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);  
}

void tilter::moveFor(double degToRotate, int speed){
  tilt1.startRotateFor(degToRotate,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  tilt2.rotateFor(degToRotate,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
}

void tilter::Stop(bool type){
  if(type){
    tilt1.stop(vex::brakeType::coast);  
    tilt2.stop(vex::brakeType::coast);            
  }else{
    tilt1.stop(vex::brakeType::hold);   
    tilt2.stop(vex::brakeType::hold);             
  }  
}

void tilter::buttonReset(){
  if(Bumper.pressing()){
    tilt1.resetRotation();
    tilt2.resetRotation();
  }
}




void tilter::userControl(){
  if(tiltInBtn && tiltOutBtn){
    this->Spin(this->slowSpeed);                      
  }else if(tiltInBtn){ 
    this->Spin(this->inSpeed);  
  }else if(tiltOutBtn){
    this->Spin(this->outSpeed);  
  }else{
    if(tilt1.rotation(vex::rotationUnits::deg)<=75){
      this->Stop(1);        
    }else{
      this->Stop(0);           
    }     
  }
  if(autoScoreBtn){
    this->Spin(-60);
  }
  this->buttonReset();
}


void tilter::robotDeploy(){
  //myIntake.Spin(-100);
  //vex::task::sleep(200);
  this->Spin(100);
  myIntake.Spin(50);
  vex::task::sleep(200);
  while(!tiltBumpBtn){
    this->Spin(-100);
  }
  this->Stop(false);
  myIntake.Spin(0);
  vex::task::sleep(500);
  myBase.Spin(-100, -100);
  vex::task::sleep(250); 
  myBase.Hold();
}

void tilter::autoScoreStack(){
  while(!tiltBumpBtn){
    this->Spin(-80);
  }
  while(tilt1.rotation(vex::rotationUnits::deg)<=75){
    this->Spin(this->slowSpeed);
  }
  this->Stop(0);

  this->autoScore();
  vex::task::sleep(1000);
}
/*





void moveTitl(tiltType mydirection, int speed=0, int timeOut=2){
  if(mydirection == extend){
    tilt1.setTimeout(timeOut,vex::timeUnits::sec);
    tilt1.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
    tilt2.spin(vex::directionType::rev,speed,vex::velocityUnits::rpm);    
  }
  else if(mydirection == retract){
    tilt1.setTimeout(timeOut,vex::timeUnits::sec);
    tilt1.spin(vex::directionType::rev,speed,vex::velocityUnits::rpm);
    tilt2.spin(vex::directionType::fwd,speed,vex::velocityUnits::rpm);
  }
  else{
    tilt1.stop(vex::brakeType::hold);
    tilt2.stop(vex::brakeType::hold);
  }
}





void deployslide(int speed,int distance ) {
  tilt1.resetRotation() ;
  tilt1.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
  tilt2.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);    
  
  while(tilt1.rotation(vex::rotationUnits::deg)<distance ){
    vex::task::sleep(1) ;
  }
  tilt1.stop(vex::brakeType::coast);
  tilt2.stop(vex::brakeType::coast);
  tilt2.resetRotation() ;
  tilt1.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  tilt2.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
  while(!(Bumper.pressing())) 
  vex::task::sleep(1) ;
  tilt1.stop(vex::brakeType::coast);
  tilt2.stop(vex::brakeType::coast);
  turnonbase(40,false) ;
  vex::task::sleep(500) ;
}


*/


tilter myTilter;

