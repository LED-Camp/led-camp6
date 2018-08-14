#include "Controller.h"

Controller* Controller::_instance = 0;

Controller* Controller::getInstance(void){
  if(_instance == 0){
    _instance = new Controller();
  }

  return _instance;

}

Controller::Controller(void){
  motor = Motor::getInstance();
  position = Position::getInstance();
}


void Controller::reset(void){
  position->reset();
}

void Controller::getPosition(float* distance, float* angle){
  position->getPosition(distance, angle);
}

void Controller::setDir(int indirA, int indirB){
  position->setDir(indirA, indirB);
}

void Controller::changeDriveMode(Mode mode, int voltage_level){
  motor->changeDriveMode(mode, voltage_level, position);
}
