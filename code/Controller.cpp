#include <stdio.h>
#include "rctank.h"
#include "PreEvent.h"
#include "Controller.h"

Controller::Controller(Position *position){
  this->state = _STATE_INITIAL;

  motorL = new DcMotor(5, 6);
  motorR = new DcMotor(13,19);
}

void Controller::execState(){
  switch(this->state){
  case STATE_FORWARD:
    
    break;
  case STATE_BACKWARD:
    
    break;
  case STATE_LEFT:
    
    break;
  case STATE_RIGHT:
    
    break;
  case STATE_STOP:
    
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
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, 5, motorL, motorR);
printf("STOP\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_LEFT;

      //entry
      ChangeDriveMode(CCW, 10, motorL, motorR);
printf("LEFT\n");
    }
    else
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RIGHT;

      //entry
      ChangeDriveMode(CW, 10, motorL, motorR);
printf("RIGHT\n");
    }
    break;
  case STATE_BACKWARD:
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RIGHT;

      //entry
      ChangeDriveMode(CW, 10, motorL, motorR);
printf("RIGHT\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_LEFT;

      //entry
      ChangeDriveMode(CCW, 10, motorL, motorR);
printf("LEFT\n");
    }
    else
    if(((event & E_UP) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, 5, motorL, motorR);
printf("STOP\n");
    }
    break;
  case STATE_LEFT:
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, 8, motorL, motorR);
printf("BACKWARD\n");
    }
    else
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, 5, motorL, motorR);
printf("STOP\n");
    }
    break;
  case STATE_RIGHT:
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, 8, motorL, motorR);
printf("BACKWARD\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, 5, motorL, motorR);
printf("STOP\n");
    }
    break;
  case STATE_STOP:
    if(((event & E_UP) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      ChangeDriveMode(FORWARD, 8, motorL, motorR);
printf("FORWARD\n");
    }
    else
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, 8, motorL, motorR);
printf("BACKWARD\n");
    }
    else
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RIGHT;

      //entry
      ChangeDriveMode(CW, 10, motorL, motorR);
printf("RIGHT\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_LEFT;

      //entry
      ChangeDriveMode(CCW, 10, motorL, motorR);
printf("LEFT\n");
    }
    break;
  default:
    break;
  }
}
