#include <stdio.h>
#include "PreEvent.h"
#include "PreTank.h"

PreTank::PreTank(PreController *precontroller){
  this->state = _STATE_INITIAL;

  this->precontroller = precontroller;

  this->distance = 0;
  this->angle = 0;
}

void PreTank::execState(){
  switch(this->state){
  case STATE_FORWARD:
    precontroller->getPosition(&distance, &angle);

    break;
  case STATE_STOP:
    
    break;
  case STATE_TURN:
    precontroller->getPosition(&distance, &angle);
    break;
  default:
    break;
  }
}

void PreTank::doTransition(unsigned long event){
  this->beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_STOP;

    //entry
    precontroller->ChangeDriveMode(STOP, 5);
printf("STOP\n");

    break;
  case STATE_FORWARD:

    if(((event & E_CHANGE_DISTANCE) != 0) && (this->distance > 10)){

      // exit
      

      //action
      

      this->state = STATE_TURN;

      //entry
      precontroller->reset();
precontroller->setDir(DIR_FORWARD,DIR_BACK);
precontroller->ChangeDriveMode(CW, 5);
printf("CW\n");
    }
    break;
  case STATE_STOP:

    if(TRUE ){

      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      precontroller->reset();
precontroller->setDir(DIR_FORWARD,DIR_FORWARD);
precontroller->ChangeDriveMode(FORWARD, 5);
printf("FORWARD\n");
    }
    break;
  case STATE_TURN:

    if(((event & E_CHANGE_ANGLE) != 0) && (this->angle > 90)){

      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      precontroller->reset();
precontroller->setDir(DIR_FORWARD,DIR_FORWARD);
precontroller->ChangeDriveMode(FORWARD, 5);
printf("FORWARD\n");
    }
    break;
  default:
    break;
  }
}
