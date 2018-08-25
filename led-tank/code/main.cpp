#include <iostream>
#include <time.h>
#include "PreEvent.h"
#include "Position.h"
#include <sys/time.h>

#include "Controller.h"


int main(void){
  struct timeval now;
  struct timeval old;

  Position *position;
  PreEvent *preEvent;

  Controller *controller;

  if( wiringPiSetupGpio() < 0){ //initialize failed
    return 1;
  }

  position = Position::getInstance(2, 3);

  controller = new Controller(position);

  preEvent = new PreEvent(position);

  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while(true){
    while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.05F){
      gettimeofday(&now, NULL);
    }
    old = now;

    preEvent->updatePreEvent();

    controller->execState();
    controller->doTransition(preEvent->getPreEvent());
  }


  delete controller;
  delete preEvent;
}
