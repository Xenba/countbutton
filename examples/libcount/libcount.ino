#include "countButton.h"
countButton bt(50,0);
void setup() {
Serial.begin(115200);
bt.begin();
}

void loop() {
bt.countBT();
}
