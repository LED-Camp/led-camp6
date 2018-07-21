#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "Motor.h"
#include "Position.h"

class Controller{
 private:
  Motor *motor;
  Position *position;

 protected:
  Controller(void);

 public:
  static Controller* _instance;

  static Controller* getInstance(void);

  // Positionån
  void reset(void);
  void getPosition(float* distance, float* angle);
  void setDir(int indirA, int indirB);

  // Motorån
  void changeDriveMode(Mode mode, int voltage_level);
};


#endif
