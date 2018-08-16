#include <stdio.h>
#include "PreEvent.h"
#include "LEDTank.h"

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;

  this->controller = controller;

  this->distance = 0;
  this->angle = 0;
  this->cnt = 0;
}

void LEDTank::execState(){
  switch(this->state){
  case STATE_FORWARD:
    controller->getPosition(&distance, &angle);
    break;
  case STATE_TURN:
    controller->getPosition(&distance, &angle);
    break;
  case STATE_INIT:
    
    break;
  case STATE_STOP:
    
    break;
  default:
    break;
  }
}

void LEDTank::doTransition(unsigned long event){
  this->beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_INIT;

    //entry
    cnt = 0;

    break;
  case STATE_FORWARD:

    if(((event & E_CHANGE_DISTANCE) != 0) && (distance > 100.0)){

      // exit
      

      //action
      

      this->state = STATE_TURN;

      //entry
      printf("[TURN]\n");
controller->reset();
controller->changeDriveMode(CW, 5);
    }
    break;
  case STATE_TURN:

    if(((event & E_CHANGE_ANGLE) != 0) && (angle > 90.0 && cnt < 4)){

      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      printf("[FORWARD]\n");
controller->reset();
controller->changeDriveMode(FORWARD, 5);
cnt++;
    }
    else

    if(((event & E_CHANGE_ANGLE) != 0) && (angle > 90.0 && cnt >= 4)){

      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      printf("[STOP]\n");
controller->changeDriveMode(STOP, 5);
    }
    break;
  case STATE_INIT:

    if(TRUE ){

      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      printf("[FORWARD]\n");
controller->reset();
controller->changeDriveMode(FORWARD, 5);
cnt++;
    }
    break;
  case STATE_STOP:
    break;
  default:
    break;
  }
}
