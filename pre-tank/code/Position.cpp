#include <stdio.h>
#include "Position.h"

static int dirA;
static int dirB;
int countA;  // 事前実習用にグローバル化
int countB;  // 事前実習用にグローバル化
int countAMoveVal;
int countBMoveVal;

/*******************************************/
Position* Position::_instance = 0;

void interruptCountA(void){
  // PreEvent.cpp無いで割り込みを定期的に模擬
  // pretank内で設定した移動量だけカウントする
  countA += countAMoveVal * dirA;
}


void interruptCountB(void){
  // PreEvent.cpp無いで割り込みを定期的に模擬
  // pretank内で設定した移動量だけカウントする
  countB += countBMoveVal * dirB;
}


Position* Position::getInstance(void){
  if(_instance == 0){
    _instance = new Position();
  }

  return _instance;
}

Position::Position(void) :
  angle(0.0F),
  distance(0.0F)
{
  countA = 0;
  countB = 0;

  dirA = DIR_FORWARD;
  dirB = DIR_FORWARD;

}

void Position::reset(void){
  countA = 0;
  countB = 0;
}

void Position::getPosition(float* distance, float* angle){
  float l;
  float r;

  float distanceTemp;

  l = countA * COUNT_TO_M;
  r = countB * COUNT_TO_M;

  distanceTemp = (l + r)/2.0;

  *angle = ((l - r) / L) * 180.0 / 3.141592653589793F;
  *distance = distanceTemp;

}

void Position::setDir(int indirA, int indirB)
{
  dirA = indirA;
  dirB = indirB;
}
