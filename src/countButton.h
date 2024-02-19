#ifndef countButton_h
#define countButton_h
#include "Arduino.h"

constexpr unsigned int BTN_Default_time = 25;
class countButton{
  protected:
  uint8_t _btstatus;
  uint8_t _poll;
  int _t;
  uint8_t _risingEdge;
  uint8_t _debounceStarted;
  unsigned int _pushDebounceInterval;
  unsigned int _releaseDebounceInterval;
  unsigned long long timestart; //anti-interference time
  int count = 0 ;//Create a button counter variable equal to 0
  public:
  countButton(int t);
  bool countBT(uint8_t lastbtstate);
};
#endif