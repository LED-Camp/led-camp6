/**
 * @file PreEvent.h
 * @brief ÉCÉxÉìÉgä«óù
 * @author Naoki Okayama
 * @date 2017/06/28
 */

#ifndef __EVENT_H__
#define __EVENT_H__

class PreController;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)

class PreEvent{
public:
  PreEvent();
  void updatePreEvent();
  unsigned long getPreEvent();
  
 private:
  unsigned long event;
  PreController *preController;
};

#endif

