#ifndef __POSITION_H__
#define __POSITION_H__

#define DIR_FORWARD (1)
#define DIR_BACK (-1)

class Position{
 private:
  const float COUNT_TO_M = 3.73F * 3.1415926535897932384626433F / 58.0F / 8.0F;
  const float L = 9.0F;  //9cm
  float angle;
  float distance;

 protected:
  Position(void);

 public:
  static Position* _instance;

  static Position* getInstance(void);
  void reset(void);
  void getPosition(float* distance, float* angle);
  void setDir(int indirA, int indirB);
};

extern int countA;  // ���O���K�p�ɃO���[�o����
extern int countB;  // ���O���K�p�ɃO���[�o����
extern int countAMoveVal;
extern int countBMoveVal;

void interruptCountA(void);    // ���O���K�p�ɃO���[�o����
void interruptCountB(void);    // ���O���K�p�ɃO���[�o����


#endif