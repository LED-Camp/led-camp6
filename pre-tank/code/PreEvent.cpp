/**
 * @file PreEvent.cpp
 * @brief �C�x���g�Ǘ�
 * @author Naoki Okayama
 * @date 2017/06/28
 */
#include "stdio.h"
#include "PreEvent.h"
#include "PreController.h"

#define ABS_FLOAT(a) ((a) < 0.0F?(a)*-1.0F:(a))

//////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////
/**
 * @brief �R���X�g���N�^
 * @param -
 * @return -
 * @sa -
 */
PreEvent::PreEvent(PreController *precontroller) :
  distanceOld(0.0F),
  angleOld(0.0F)
{
  this->event = 0;
  this->precontroller = precontroller;
}

/**
 * @brief �C�x���g���X�V����
 * @parame -
 * @return -
 * @sa -
 */
void PreEvent::updatePreEvent(){
  char c;
  float distance;
  float angle;

  float absDistanceDiff;
  float absAngleDiff;

  // ���荞�ݖ͋[
  interruptCountA();
  interruptCountB();

  precontroller->getPosition(&distance, &angle);

  absDistanceDiff = ABS_FLOAT(this->distanceOld - distance);
  absAngleDiff = ABS_FLOAT(this->angleOld - angle);

  if(absDistanceDiff > 0.005){
    this->event |= E_CHANGE_DISTANCE;
  }else{
    this->event &= ~E_CHANGE_DISTANCE;
  }

  if(absAngleDiff > 0.01){
    this->event |= E_CHANGE_ANGLE;
  }else{
    this->event &= ~E_CHANGE_ANGLE;
  }

  printf("distance=%lf, angle=%lf\n", distance, angle);

  this->distanceOld = distance;
  this->angleOld = angle;

}


/**
 * @brief �C�x���g���擾����
 * @parame -
 * @return �C�x���g
 * @sa -
 */
unsigned long PreEvent::getPreEvent(){
  return this->event;
}
