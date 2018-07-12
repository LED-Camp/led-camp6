#ifndef __PRECONTROLLER__
#define __PRECONTROLLER__

#include "Motor.h"
#include "Position.h"

class PreController{
 private:
  Motor *motor;
  Position *position;

 protected:
  PreController(void);

 public:
  static PreController* _instance;

  static PreController* getInstance(void);

  // Positionån
  void reset(void);
  void getPosition(float* distance, float* angle);
  void setDir(int indirA, int indirB);

  // Motorån
  void ChangeDriveMode(Mode mode, int voltage_level);
};


#endif
