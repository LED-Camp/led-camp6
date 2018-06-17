#include <stdio.h>
#include "rctank.h"
#include "PreEvent.h"
#include "Controller.h"

Controller::Controller(Position *position){
  this->state = _STATE_INITIAL;

  this->distance = 0;
  this->angle = 0;
  motorL = new DcMotor(5, 6);
  motorR = new DcMotor(13,19);
}

void Controller::execState(){
  switch(this->state){
  case STATE_FORWARD:
    position->getPosition(&distance, &angle);

    break;
  case STATE_STOP:
    
    break;
  case STATE_TURN:
    position->getPosition(&distance, &angle);
    break;
  default:
    break;
  }
}

void Controller::doTransition(unsigned long event){
  this->beforeState = this->state;

  switch(this->state){
  case _STATE_INITIAL:
    this->state = STATE_STOP;

    //entry
    ChangeDriveMode(STOP, 5, motorL, motorR);
printf("STOP\n");

    break;
  case STATE_FORWARD:
    if(((event & E_CHANGE_ANGLE) != 0) && (this->distance > 10)){
      // exit
      

      //action
      

      this->state = STATE_TURN;

      //entry
      ChangeDriveMode(CW, 5, motorL, motorR);
printf("CW\n");
    }
    break;
  case STATE_STOP:
    if(((event & E_UP) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      ChangeDriveMode(FORWARD, 5, motorL, motorR);
printf("FORWARD\n");
    }
    break;
  case STATE_TURN:
    if(((event & E_CHANGE_ANGLE) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      ChangeDriveMode(FORWARD, 5, motorL, motorR);
printf("FORWARD\n");
    }
    break;
  default:
    break;
  }
}
