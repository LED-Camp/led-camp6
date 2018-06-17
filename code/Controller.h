#ifndef __Controller__
#define __Controller__

#include "rctank.h"
#include "Position.h"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_STOP ((unsigned long)2)
#define STATE_TURN ((unsigned long)3)

class PreController;

class Controller{
 public:
  Controller(Position *position);
  void execState();
  void doTransition(unsigned long event);

 private:
  DcMotor *motorL;
  DcMotor *motorR;
  Position *position;

  unsigned long state;
  unsigned long beforeState;
  PreController *preController;
  float distance;
  float angle;
};

#endif