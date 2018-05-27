/**
 * @file PreEvent.cpp
 * @brief イベント管理
 * @author Naoki Okayama
 * @date 2017/06/28
 */
#include "iostream"
#include "PreEvent.h"
#include <unistd.h>   //_getch
#include <termios.h>  //_getch

char getch(){
  char buf=0;
  struct termios old={0};
  fflush(stdout);
  if(tcgetattr(0, &old)<0)
    perror("tcsetattr()");
  old.c_lflag&=~ICANON;
  old.c_lflag&=~ECHO;
  old.c_cc[VMIN]=1;
  old.c_cc[VTIME]=0;
  if(tcsetattr(0, TCSANOW, &old)<0)
    perror("tcsetattr ICANON");
  if(read(0,&buf,1)<0)
    perror("read()");
  old.c_lflag|=ICANON;
  old.c_lflag|=ECHO;
  if(tcsetattr(0, TCSADRAIN, &old)<0)
    perror ("tcsetattr ~ICANON");
  //  printf("%c\n",buf);
  return buf;
}

//////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////
/**
 * @brief コンストラクタ
 * @param -
 * @return -
 * @sa -
 */
PreEvent::PreEvent(){
  this->event = 0;
}

/**
 * @brief イベントを更新する
 * @parame -
 * @return -
 * @sa -
 */
void PreEvent::updatePreEvent(){
  char c;

  c = getch();
  
  // E_UPイベント判定
  if(c == 'w'){
    this->event |= E_UP;
  }else{
    this->event &= ~E_UP;
  }

  // E_DOWNイベント判定
  if(c == 's'){
    this->event |= E_DOWN;
  }else{
    this->event &= ~E_DOWN;
  }

  // E_LEFTイベント判定
  if(c == 'a'){
    this->event |= E_LEFT;
  }else{
    this->event &= ~E_LEFT;
  }

  // E_RIGHTイベント判定
  if(c == 'd'){
    this->event |= E_RIGHT;
  }else{
    this->event &= ~E_RIGHT;
  }

    
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
