#include <stdio.h>
#include "rctank.h"
#include "PreEvent.h"
#include "Controller.h"
#include <unistd.h>

#define Duty 6
Controller::Controller(Position *position, RangingSensor *rangingSensor){
  this->state = _STATE_INITIAL;

  motorL = new DcMotor(5, 6);
  motorR = new DcMotor(13,19);
}

void Controller::execState(float &distance, float &angle, float &before_angle){
  switch(this->state){
  case STATE_FORWARD:
    before_angle = angle;
    break;
  case STATE_BACKWARD:
    before_angle = angle;
    break;
  case STATE_LEFT:
    before_angle = angle;
    break;
  case STATE_RIGHT:
    before_angle = angle;
    break;
  case STATE_STOP:
    before_angle = angle;
    break;
  case STATE_AVOID:
    printf("angle = %f, before_angle = %f\n", angle, before_angle);
    if( (((angle - before_angle) < 85) && ((angle - before_angle) > 0))||
    	(((angle - before_angle) > -85) && ((angle - before_angle) < 0)) ){
      //回転角度検出の精度によってここの値変えないといけない
      ChangeDriveMode(CW, Duty, motorL, motorR);
    }
    else{
      avoidComplete = true;
    }
    

               
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
    ChangeDriveMode(STOP, Duty, motorL, motorR);
    printf("STOP\n");

    break;
  case STATE_FORWARD:
    if(((event & E_RANGING_STOP
	 ) != 0) ){
      // exit
      

      //action
      
      this->state = STATE_AVOID;
      this->avoidComplete = false;

      //entry
      ChangeDriveMode(STOP, Duty, motorL, motorR);
      printf("AVOID\n");
      sleep(1);
 
    }

    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, Duty, motorL, motorR);
      printf("STOP\n");
    }
    else
      if(((event & E_LEFT) != 0) ){
	// exit
      

	//action
      

	this->state = STATE_LEFT;

	//entry
	ChangeDriveMode(CCW, Duty, motorL, motorR);
	printf("LEFT\n");
      }
      else
	if(((event & E_RIGHT) != 0) ){
	  // exit
      

	  //action
      

	  this->state = STATE_RIGHT;

	  //entry
	  ChangeDriveMode(CW, Duty, motorL, motorR);
	  printf("RIGHT\n");
	}
    break;
  case STATE_BACKWARD:
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RIGHT;

      //entry
      ChangeDriveMode(CW, Duty, motorL, motorR);
      printf("RIGHT\n");
    }
    else
      if(((event & E_LEFT) != 0) ){
	// exit
      

	//action
      

	this->state = STATE_LEFT;

	//entry
	ChangeDriveMode(CCW, Duty, motorL, motorR);
	printf("LEFT\n");
      }
      else
	if(((event & E_UP) != 0) ){
	  // exit
      

	  //action
      

	  this->state = STATE_STOP;

	  //entry
	  ChangeDriveMode(STOP, Duty, motorL, motorR);
	  printf("STOP\n");
	}
    break;
  case STATE_LEFT:
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, Duty, motorL, motorR);
      printf("BACKWARD\n");
    }
    else
      if(((event & E_RIGHT) != 0) ){
	// exit
      

	//action
      

	this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, Duty, motorL, motorR);
printf("STOP\n");
    }
    break;
  case STATE_RIGHT:
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, Duty, motorL, motorR);
printf("BACKWARD\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      ChangeDriveMode(STOP, Duty, motorL, motorR);
printf("STOP\n");
    }
    break;
  case STATE_STOP:
    if(((event & E_UP) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_FORWARD;

      //entry
      ChangeDriveMode(FORWARD, Duty, motorL, motorR);
printf("FORWARD\n");
    }
    else
    if(((event & E_DOWN) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_BACKWARD;

      //entry
      ChangeDriveMode(BACKWARD, Duty, motorL, motorR);
printf("BACKWARD\n");
    }
    else
    if(((event & E_RIGHT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_RIGHT;

      //entry
      ChangeDriveMode(CW, Duty, motorL, motorR);
printf("RIGHT\n");
    }
    else
    if(((event & E_LEFT) != 0) ){
      // exit
      

      //action
      

      this->state = STATE_LEFT;

      //entry
      ChangeDriveMode(CCW, Duty, motorL, motorR);
printf("LEFT\n");
    }

    break;
      case STATE_AVOID:
    if(this->avoidComplete){
      this->avoidComplete = false;
      this->state = STATE_FORWARD;
      ChangeDriveMode(FORWARD, Duty, motorL, motorR);
    }else{
      printf("avoiding...\n");
    }
    break;

  default:
    break;
  }
}
