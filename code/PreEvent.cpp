/**
 * @file PreEvent.cpp
 * @brief �C�x���g�Ǘ�
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
 * @brief �R���X�g���N�^
 * @param -
 * @return -
 * @sa -
 */
PreEvent::PreEvent(){
  this->event = 0;
}

/**
 * @brief �C�x���g���X�V����
 * @parame -
 * @return -
 * @sa -
 */
void PreEvent::updatePreEvent(){
  char c;

  c = getch();
  
  // E_UP�C�x���g����
  if(c == 'w'){
    this->event |= E_UP;
  }else{
    this->event &= ~E_UP;
  }

  // E_DOWN�C�x���g����
  if(c == 's'){
    this->event |= E_DOWN;
  }else{
    this->event &= ~E_DOWN;
  }

  // E_LEFT�C�x���g����
  if(c == 'a'){
    this->event |= E_LEFT;
  }else{
    this->event &= ~E_LEFT;
  }

  // E_RIGHT�C�x���g����
  if(c == 'd'){
    this->event |= E_RIGHT;
  }else{
    this->event &= ~E_RIGHT;
  }

    
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
