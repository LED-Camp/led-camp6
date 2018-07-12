#include <stdio.h>
#include "Position.h"

static int dirA;
static int dirB;
int countA;  // ���O���K�p�ɃO���[�o����
int countB;  // ���O���K�p�ɃO���[�o����
int countAMoveVal;
int countBMoveVal;

/*******************************************/
Position* Position::_instance = 0;

void interruptCountA(void){
  // PreEvent.cpp�����Ŋ��荞�݂����I�ɖ͋[
  // pretank���Őݒ肵���ړ��ʂ����J�E���g����
  countA += countAMoveVal * dirA;
}


void interruptCountB(void){
  // PreEvent.cpp�����Ŋ��荞�݂����I�ɖ͋[
  // pretank���Őݒ肵���ړ��ʂ����J�E���g����
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
