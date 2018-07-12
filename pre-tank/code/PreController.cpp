#include "PreController.h"

PreController* PreController::_instance = 0;

PreController* PreController::getInstance(void){
  if(_instance == 0){
    _instance = new PreController();
  }

  return _instance;

}

PreController::PreController(void){
  motor = Motor::getInstance();
  position = Position::getInstance();
}


void PreController::reset(void){
  position->reset();
}

void PreController::getPosition(float* distance, float* angle){
  position->getPosition(distance, angle);
}

void PreController::setDir(int indirA, int indirB){
  position->setDir(indirA, indirB);
}

void PreController::ChangeDriveMode(Mode mode, int voltage_level){
  motor->ChangeDriveMode(mode, voltage_level);
}
