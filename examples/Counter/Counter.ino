#include <Multiplex7Seg4Digit.h>

const int latchPin  = 8;
const int clockPin  = 12;
const int dataPin   = 11;

Multiplex7Seg4Digit disp(8,12,11);
int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  disp.displayNum(counter++);
  delay(500);
}
