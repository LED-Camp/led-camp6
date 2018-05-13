#include <iostream>
#include <time.h>
#include "PreEvent.h"
  #include "Controller.h"


int main(void){
  clock_t now;
  clock_t old;

  PreEvent *preEvent;
  float n;

  preEvent = new PreEvent();

  if( wiringPiSetupGpio() < 0){ //initialize failed
    return 1;
  }
  Controller *controller;

  controller = new Controller();

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
