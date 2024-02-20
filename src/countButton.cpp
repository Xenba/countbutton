#include "countButton.h"

countButton::countButton(int t,uint8_t p){
_btstatus = 0 ;
_poll = 0;
_t = t;
_risingEdge = false;
_debounceStarted = false;
p =pin;
}
void countButton::begin(){
pinMode(pin,INPUT);

}
bool countButton::countBT() {
lastbtstate= digitalRead(pin);
  if (lastbtstate != _poll) { // Kiểm tra bất kỳ thay đổi trạng thái nào
    timestart = millis(); // Đặt lại bộ hẹn giờ chỉ khi thay đổi đầu tiên
    _debounceStarted = true;
    if (lastbtstate && !_btstatus) { // Cạnh lên (nhấn nút)
      _btstatus = lastbtstate;
      _risingEdge = true;
    }
  } else if (_debounceStarted && (millis() - timestart) > _t) { // Kiểm tra thời gian chờ sau thay đổi đầu tiên
    _btstatus = lastbtstate; // Cập nhật trạng thái trong trường hợp bỏ lỡ cạnh
    _debounceStarted = false;
  }

  if (_risingEdge) {
    _risingEdge = false;
    count++;
    Serial.println(count);
    return true; // Cho biết thay đổi trạng thái và tăng số đếm
  }

  return false; // Không có sự kiện kích hoạt hoặc hết thời gian chờ
}
