#include "vex.h"
/*---------------------------------------------------------------------------*/
/*                            PID Functions                                  */
/*---------------------------------------------------------------------------*/

class pidController{
    private:
        double min = -100.0; // min - minimum value of manipulated variable
        double max = 100.0; // max - maximum value of manipulated variable
        double Kp = 0.02; // Kp -  proportional gain 
        double Ki = 0.0; // Ki -  Integral gain
        double integral = 0.0;
    public:
        pidController(double min, double max, double Kp, double Ki, double Kd, double dt);
        double speed(double currentVal, double desiredVal);
        double error = 0.0;
        double pre_error = 0.0;
        bool enabled = true;
        double dt = 0.0001; // dt -  loop interval time
        double Kd = 0.0; // Kd -  derivative gain
};

pidController::pidController(double min, double max, double Kp, double Ki, double Kd, double dt){
    this->min = min;
    this->max = max;
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->dt = dt;
}

double pidController::speed(double currentVal, double desiredVal){
    error = desiredVal - currentVal;
    double Pout = Kp * error; // Proportional term
    integral += error * dt;
    double Iout = Ki * integral; // Integral term
    double derivative = (error - pre_error) / dt; // Derivative term
    double Dout = Kd * derivative;
    double output = Pout + Iout + Dout;// Calculate total output 
    if(output > max) // Restrict to max/min
        output = max;
    else if(output < min)
        output = min;
    pre_error = error; // Save error to previous error
    dt += 0.001;
    return output; //Speed = (_Kp*error)+(_Ki*error*_dt)+(_Kd*((error-_pre_error)/_dt))
}

//pidController(double min, double max, double Kp, double Ki, double Kd, double dt);
//pidController drive(-100.0, 100.0, 0.060, 0.0000300, 0.050, 0.0001);

pidController drive(-100.0, 100.0, 0.060, 0.0000300, 0.045, 0.0001);
pidController turn(-100.0, 100.0, 2.500, 0.0000300, 0.050, 0.0001);
