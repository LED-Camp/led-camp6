#include <stdio.h>
#include "Event.h"
#include "LEDTank.h"

LEDTank::LEDTank(Controller *controller){
  this->state = _STATE_INITIAL;

  this->controller = controller;

}

void LEDTank::execState(){
  switch(this->state){
  case STATE_FORWARD:
    controller->getPosition(&distance, &angle);
ranging = controller->getRanging();
    break;
  case STATE_TURN:
    controller->getPosition(&distance, &angle);
    break;
  case STATE_INIT:
    
    break;
  case STATE_STOP:
    
    break;
  case STATE_SLOW:
    controller->getPosition(&distance, &angle);
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
distance = 0.0;
angle = 0.0;


    break;
  case STATE_FORWARD:

    if(((event & E_CHANGE_RANGING) != 0) && (ranging < 40.0)){

      // exit
      

      //action
      

      this->state = STATE_SLOW;

      //entry
      printf("[SLOW]\n");
controller->changeDriveMode(FORWARD, 50);
cnt++;
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
controller->changeDriveMode(FORWARD, 80);
cnt++;
    }
    else

    if(((event & E_CHANGE_ANGLE) != 0) && (angle > 90.0 && cnt >= 4)){

      // exit
      

      //action
      

      this->state = STATE_STOP;

      //entry
      printf("[STOP]\n");
controller->changeDriveMode(STOP, 0);
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
controller->changeDriveMode(FORWARD, 80);
cnt++;
    }
    break;
  case STATE_STOP:
    break;
  case STATE_SLOW:

    if(((event & E_REACH) != 0) ){

      // exit
      

      //action
      

      this->state = STATE_TURN;

      //entry
      printf("[TURN]\n");
controller->getNextScoreTable(scoreTable);
printf("score : %d,%d,%d,%d\n",scoreTable[0],scoreTable[1],scoreTable[2],scoreTable[3]);
controller->reset();
controller->changeDriveMode(CW, 50);
    }
    break;
  default:
    break;
  }
}
