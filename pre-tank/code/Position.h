#ifndef __POSITION_H__
#define __POSITION_H__

#define DIR_FORWARD (1)
#define DIR_BACK (-1)

class Position{
 private:
  const float COUNT_TO_M = 1;
  const float L = 100.0F;
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
