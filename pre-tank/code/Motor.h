#ifndef __MOTOR__
#define __MOTOR__

class Position;

typedef enum{
  STOP,
  FORWARD,
  BACKWARD,
  CW,
  CCW
} Mode;

class Motor
{
 private:
  static Motor* _instance;
 protected:
  Motor(void);
 public:
  static Motor* getInstance(void);
  void changeDriveMode(Mode mode, int voltage_level, Position* position);
};

#endif
