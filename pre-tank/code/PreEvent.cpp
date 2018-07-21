/**
 * @file PreEvent.cpp
 * @brief イベント管理
 * @author Naoki Okayama
 * @date 2017/06/28
 */
#include "stdio.h"
#include "PreEvent.h"
#include "Controller.h"

#define ABS_FLOAT(a) ((a) < 0.0F?(a)*-1.0F:(a))

//////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////
/**
 * @brief コンストラクタ
 * @param -
 * @return -
 * @sa -
 */
PreEvent::PreEvent(Controller *controller) :
  distanceOld(0.0F),
  angleOld(0.0F)
{
  this->event = 0;
  this->controller = controller;
}

/**
 * @brief イベントを更新する
 * @parame -
 * @return -
 * @sa -
 */
void PreEvent::updatePreEvent(){
  float distance;
  float angle;

  float absDistanceDiff;
  float absAngleDiff;

  // 割り込み模擬
  interruptCountA();
  interruptCountB();

  controller->getPosition(&distance, &angle);

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
 * @brief イベントを取得する
 * @parame -
 * @return イベント
 * @sa -
 */
unsigned long PreEvent::getPreEvent(){
  return this->event;
}
