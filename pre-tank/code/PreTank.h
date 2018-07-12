#ifndef __PreTank__
#define __PreTank__

#include "PreController.h"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_STOP ((unsigned long)2)
#define STATE_TURN ((unsigned long)3)

class PreController;

class PreTank{
 public:
  PreTank(PreController *precontroller);
  void execState();
  void doTransition(unsigned long event);

 private:
  PreController *precontroller;
  unsigned long state;
  unsigned long beforeState;
  PreController *preController;
  float distance;
  float angle;
};

#endif