/*
  Multiplex7Seg4Digit is an Arduino library that allows you to display numbers
  on the 7-segment 4-digit display (12 pins) connected to 2 multiplexors.
  So you can use only 3 Arduino pins instead of 12 if you connect a display directly to Arduino board.
*/
  
#include "Multiplex7Seg4Digit.h"
#include <Arduino.h>
#include <MsTimer2.h>

const int Multiplex7Seg4Digit::ARR_POS[4] = {DIG_1, DIG_2, DIG_3, DIG_4};
const int Multiplex7Seg4Digit::ARR_NUM[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

static Multiplex7Seg4Digit *pclass = 0;

void Multiplex7Seg4Digit::update() {
  if (pclass && pclass->_isNumDefined) {

    if(pclass->_num < 0 || pclass->_num > 9999) return;

    // Crear display. We can't just use clear() method here
    digitalWrite(pclass->_latchPin, LOW);
    shiftOut(pclass->_dataPin, pclass->_clockPin, MSBFIRST , 0b00000000);
    shiftOut(pclass->_dataPin, pclass->_clockPin, MSBFIRST , 0b00000000);
    digitalWrite(pclass->_latchPin, HIGH);

    String numStr = String(pclass->_num);
    
    if(pclass->_num < 10) {
      pclass->displayDecimal(pclass->_num, 3);
    } else if(pclass->_num < 100) {
      pclass->displayDecimal(numStr.charAt(0)-'0', 2);
      pclass->displayDecimal(numStr.charAt(1)-'0', 3);
    } else if(pclass->_num < 1000) {
      pclass->displayDecimal(numStr.charAt(0)-'0', 1);
      pclass->displayDecimal(numStr.charAt(1)-'0', 2);
      pclass->displayDecimal(numStr.charAt(2)-'0', 3);
    } else if(pclass->_num < 10000) {
      pclass->displayDecimal(numStr.charAt(0)-'0', 0);
      pclass->displayDecimal(numStr.charAt(1)-'0', 1);
      pclass->displayDecimal(numStr.charAt(2)-'0', 2);
      pclass->displayDecimal(numStr.charAt(3)-'0', 3);
    }
  }
}

Multiplex7Seg4Digit::Multiplex7Seg4Digit(const int latchPin, const int clockPin, const int dataPin) {
  _latchPin = latchPin;
  _clockPin = clockPin;
  _dataPin  = dataPin;

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  clear();

  pclass = this;

  MsTimer2::set(2, update);
  MsTimer2::start();
}


void Multiplex7Seg4Digit::clear() {
  _isNumDefined = false;
  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, MSBFIRST , 0b00000000);
  shiftOut(_dataPin, _clockPin, MSBFIRST , 0b00000000);
  digitalWrite(_latchPin, HIGH);
}


void Multiplex7Seg4Digit::displayNum(int num) {
  _num = num;
  _isNumDefined = true;
}


void Multiplex7Seg4Digit::displayDecimal(int dec, int pos) {
  if(dec < 0 || dec > 9) return;
  if(pos < 0 || pos > 4) return;

  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, MSBFIRST , Multiplex7Seg4Digit::ARR_POS[pos]);
  shiftOut(_dataPin, _clockPin, MSBFIRST , Multiplex7Seg4Digit::ARR_NUM[dec]);
  digitalWrite(_latchPin, HIGH);
}