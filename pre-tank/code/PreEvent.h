/**
 * @file PreEvent.h
 * @brief ÉCÉxÉìÉgä«óù
 * @author Naoki Okayama
 * @date 2017/06/28
 */

#ifndef __EVENT_H__
#define __EVENT_H__

class Controller;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)
#define E_CHANGE_DISTANCE ((unsigned long)0x00000010)
#define E_CHANGE_ANGLE ((unsigned long)0x00000020)

#define TRUE (1)
#define FALSE (0)

class PreEvent{
public:
  PreEvent(Controller *controller);
  void updatePreEvent();
  unsigned long getPreEvent();

 private:
  unsigned long event;
  Controller *controller;

  float distanceOld;
  float angleOld;
};

#endif
