/**
 * @file PreEvent.h
 * @brief ÉCÉxÉìÉgä«óù
 * @author Naoki Okayama
 * @date 2017/06/28
 */

#ifndef __EVENT_H__
#define __EVENT_H__
#include "Position.h"
#include "RangingSensor.h"



class PreController;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)
#define E_CHANGE_DISTANCE ((unsigned long)0x00000010)
#define E_CHANGE_ANGLE ((unsigned long)0x00000020)
#define E_CHANGE_RANGING ((unsigned long)0x00000040)
#define E_RANGING_STOP ((unsigned long )0x00000080)

class PreEvent{
public:
  PreEvent(Position* position, RangingSensor* rangingSensor);
  void updatePreEvent(float &distance, float &angle);
  unsigned long getPreEvent();

 private:
  Position* position;
  unsigned long event;
  PreController *preController;

  float distanceOld;
  float angleOld;

  RangingSensor* rangingSensor;
  uint16_t rangingDistanceOld;
};

#endif
