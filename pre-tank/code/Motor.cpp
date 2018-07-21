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

void Motor::changeDriveMode(Mode mode, int voltage_level, Position* position)
{
  //voltage_level : 0 〜 10
  //double r = ((double)voltage_level / 10);

  if(mode == STOP){
    countAMoveVal = 0;
    countBMoveVal = 0;

    position->setDir(DIR_FORWARD, DIR_FORWARD);
  }else if(mode == FORWARD){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;

    position->setDir(DIR_FORWARD, DIR_FORWARD);
  }else if(mode == BACKWARD){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;

    position->setDir(DIR_BACK, DIR_BACK);
  }else if(mode == CW){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;

    position->setDir(DIR_FORWARD, DIR_BACK);
  }else if(mode == CCW){
    countAMoveVal = voltage_level;
    countBMoveVal = voltage_level;

    position->setDir(DIR_BACK, DIR_FORWARD);
  }
}
