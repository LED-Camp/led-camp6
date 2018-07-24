#include <iostream>
#include <time.h>
#include "PreEvent.h"
#include "Position.h"
#include <sys/time.h>

#include "Controller.h"


int main(void){
  struct timeval now;
  struct timeval old;

  RangingSensor *rangingSensor;
  Position *position;
  PreEvent *preEvent;
  float n;
  float distance;
  float angle;
  float before_angle;

  Controller *controller;

  if( wiringPiSetupGpio() < 0){ //initialize failed
    return 1;
  }

  rangingSensor = RangingSensor::getInstance();
  rangingSensor->Initialize();
  rangingSensor->getRanging();

  position = Position::getInstance(17, 27);

  controller = new Controller(position, rangingSensor);

  preEvent = new PreEvent(position, rangingSensor);

  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while(true){
    while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.01F){
      gettimeofday(&now, NULL);
    }
    old = now;

    preEvent->updatePreEvent(distance, angle);

    controller->execState(distance, angle, before_angle);
    controller->doTransition(preEvent->getPreEvent());
  }

  delete controller;
  delete preEvent;
}
