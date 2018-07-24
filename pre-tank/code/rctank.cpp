#include "rctank.h"
#define PWM_RANGE 10

DcMotor:: DcMotor(int pinA, int pinB)
{
  pin1 = pinA;
  pin2 = pinB;

  softPwmCreate(pin1, 0, PWM_RANGE);
  softPwmCreate(pin2, 0, PWM_RANGE);
}

DcMotor:: ~DcMotor()
{

}

void DcMotor::pwmWrite(double ratio)
{
  if(ratio > 1.0) ratio = 1.0; // saturation
  else if(ratio < -1.0) ratio = -1.0;

  if( (ratio < 0.01) && (ratio > -0.01) ){ // Stop
	softPwmWrite(pin1, 0);
	softPwmWrite(pin2, 0);
  }
  else if(ratio > 0){ // Nomal rotation
	softPwmWrite(pin1, (int)(ratio * PWM_RANGE) );
	softPwmWrite(pin2, 0);
  }
  else{ // Reverse rotation
	softPwmWrite(pin1, 0);
	softPwmWrite(pin2, (int)(-ratio * PWM_RANGE) );
  }
}


void ChangeDriveMode(Mode mode, int voltage_level, DcMotor *motorL, DcMotor *motorR)
{
  //voltage_level : 0 〜 10
  double r = ((double)voltage_level / 10);

  if(mode == STOP){
	motorL->pwmWrite(0.0);
	motorR->pwmWrite(0.0);
  }
  else if(mode == FORWARD){
	motorL->pwmWrite(r);
	motorR->pwmWrite(r);
  }
  else if(mode == BACKWARD){
	motorL->pwmWrite(-r);
	motorR->pwmWrite(-r);
  }
  else if(mode == CW){
	motorL->pwmWrite(r);
	//motorR->pwmWrite(-r);
	motorR->pwmWrite(0);
  }
  else if(mode == CCW){
    //motorL->pwmWrite(-r);
    motorL->pwmWrite(0);
	motorR->pwmWrite(r);
  }
}
