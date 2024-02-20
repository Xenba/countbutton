#ifndef countButton_h
#define countButton_h
#include "Arduino.h"
class countButton{
  protected:
  uint8_t _btstatus;
  uint8_t _poll;
  int _t;
  uint8_t _risingEdge;
  uint8_t _debounceStarted;
  uint8_t pin;
  uint8_t lastbtstate;
  unsigned int _pushDebounceInterval;
  unsigned int _releaseDebounceInterval;
  unsigned long long timestart; //anti-interference time
  int count = 0 ;//Create a button counter variable equal to 0
  public:
  countButton(int t,uint8_t p);
  bool countBT();
  void begin();
};
#endif