#include "Motor.h"
#include "Position.h"

Motor* Motor::_instance = 0;

Motor* Motor::getInstance(void){
  if(_instance == 0){
    _instance = new Motor();
  }

  return _instance;

}

Motor::Motor(void)
{
  countAMoveVal = 0;
  countBMoveVal = 0;
}

void Motor::ChangeDriveMode(Mode mode, int voltage_level)
{
  //voltage_level : 0 〜 10
  //double r = ((double)voltage_level / 10);

  if(mode == STOP){
    countAMoveVal = 0;
    countBMoveVal = 0;
  }else if(mode == FORWARD){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;
  }else if(mode == BACKWARD){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;
  }else if(mode == CW){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;
  }else if(mode == CCW){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;
  }
}
