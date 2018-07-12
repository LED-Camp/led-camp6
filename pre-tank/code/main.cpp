#include <iostream>
#include <time.h>
#include "PreEvent.h"
#include "PreController.h"
#include <sys/time.h>

#include "PreTank.h"


int main(void){
  struct timeval now;
  struct timeval old;

  PreController *precontroller;
  PreEvent *preEvent;
  float n;

  PreTank *preTank;
  precontroller = PreController::getInstance();

  preTank = new PreTank(precontroller);

  preEvent = new PreEvent(precontroller);

  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while(true){
    while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.05F){
      gettimeofday(&now, NULL);
    }
    old = now;

    preEvent->updatePreEvent();

    preTank->execState();
    preTank->doTransition(preEvent->getPreEvent());
  }

  delete preTank;
  delete preEvent;
}
