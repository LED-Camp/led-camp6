#ifndef __POSITION_H__
#define __POSITION_H__

#define DIR_CW (1)
#define DIR_CCW (-1)

class Position{
 private:
  const float COUNT_TO_M = 2.0F / 203.0F / 8.0F;
  const float L = 10.0F;  //10cm
  float angle;
  float distance;

 protected:
  Position(int pinA, int pinB);

 public:
  static Position* _instance;

  static Position* getInstance(int pinA, int pinB);
  void reset(void);
  void getPosition(float* distance, float* angle);
  void setDir(int indirA, int indirB);
};


#endif
