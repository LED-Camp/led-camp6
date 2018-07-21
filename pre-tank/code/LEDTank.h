#ifndef __LEDTank__
#define __LEDTank__

#include "Controller.h"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_TURN ((unsigned long)2)
#define STATE_INIT ((unsigned long)3)
#define STATE_STOP ((unsigned long)4)

class PreController;

class LEDTank{
 public:
  LEDTank(Controller *controller);
  void execState();
  void doTransition(unsigned long event);

 private:
  Controller *controller;
  unsigned long state;
  unsigned long beforeState;
  float distance;
  float angle;
  int cnt;
};

#endif