#include <iostream>
#include <time.h>
#include "PreEvent.h"
#include "Position.h"

  #include "Controller.h"


int main(void){
  clock_t now;
  clock_t old;
  Position *position;
  PreEvent *preEvent;
  float n;

  Controller *controller;

  if( wiringPiSetupGpio() < 0){ //initialize failed
    return 1;
  }

  position = Position::getInstance(2,3);

  controller = new Controller(position);

  preEvent = new PreEvent(position);

  now = clock();
  old = clock();

  while(true){
    while((double)((now - old)/(double)CLOCKS_PER_SEC) < 0.1){
      now = clock();
    }
    old = now;

    preEvent->updatePreEvent();

    controller->execState();
    controller->doTransition(preEvent->getPreEvent());
  }

  delete controller;
  delete preEvent;
}
