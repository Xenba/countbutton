#include "countButton.h"
countButton bt(50);
void setup() {
Serial.begin(115200);
pinMode(0,INPUT_PULLUP);
}

void loop() {
bt.countBT(digitalRead(0));
}
