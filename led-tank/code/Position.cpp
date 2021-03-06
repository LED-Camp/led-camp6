#include <stdio.h>
#include "Position.h"
#include <wiringPi.h>
#include <sys/time.h>

static int dirA;
static int dirB;
static struct timeval nowA;
static struct timeval oldA;
static struct timeval nowB;
static struct timeval oldB;
static int countA;
static int countB;


void interruptCountA(void);
void interruptCountB(void);

void interruptCountA(void){
  gettimeofday(&nowA, NULL);

  if((nowA.tv_sec - oldA.tv_sec) + (nowA.tv_usec - oldA.tv_usec)*1.0E-6 > 5.0*1.0E-6){
    if(dirA == DIR_CW){
      countA++;
    }else{
      countA--;
    }
  }else{
    printf("\terror\n");
  }

  oldA = nowA;
}


void interruptCountB(void){
  gettimeofday(&nowB, NULL);

  if((nowB.tv_sec - oldB.tv_sec) + (nowB.tv_usec - oldB.tv_usec)*1.0E-6 > 5.0*1.0E-6){
    if(dirB == DIR_CW){
      countB++;
    }else{
      countB--;
    }
  }

  oldB = nowB;
}

/*******************************************/
Position* Position::_instance = 0;


Position* Position::getInstance(int pinA, int pinB){
  if(_instance == 0){
    _instance = new Position(pinA, pinB);
  }

  return _instance;
}

Position::Position(int pinA, int pinB) :
  angle(0.0F),
  distance(0.0F)
{
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);

  gettimeofday(&nowA, NULL);
  gettimeofday(&oldA, NULL);
  gettimeofday(&nowB, NULL);
  gettimeofday(&oldB, NULL);

  countA = 0;
  countB = 0;

  dirA = DIR_CW;
  dirB = DIR_CW;

  wiringPiISR(pinA, INT_EDGE_BOTH, interruptCountA );
  wiringPiISR(pinB, INT_EDGE_BOTH, interruptCountB );

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
