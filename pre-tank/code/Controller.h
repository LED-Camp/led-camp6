#ifndef __Controller__
#define __Controller__

#include "rctank.h"
#include "Position.h"
#include "RangingSensor.h"

#define _STATE_INITIAL 0x00000000
#define STATE_FORWARD ((unsigned long)1)
#define STATE_BACKWARD ((unsigned long)2)
#define STATE_LEFT ((unsigned long)3)
#define STATE_RIGHT ((unsigned long)4)
#define STATE_STOP ((unsigned long)5)
#define STATE_AVOID ((unsigned long)6)
class PreController;

class Controller{
 public:
  Controller(Position *position, RangingSensor *rangingSensor);
  void execState(float &distance, float &angle, float &before_angle);
  void doTransition(unsigned long event);

 private:
  DcMotor *motorL;
  DcMotor *motorR;
  Position *position;
  RangingSensor *rangingSensor;

  unsigned long state;
  unsigned long beforeState;
  bool avoidComplete;
  PreController *preController;
};

#endif