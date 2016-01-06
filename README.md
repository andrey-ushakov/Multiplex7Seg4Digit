# Multiplex7Seg4Digit
Multiplex7Seg4Digit is an Arduino library that allows you to display numbers on the 7-segment 4-digit display (12 pins) connected to 2 multiplexors. So you can use only 3 Arduino pins instead of 12 if you connect a display directly to Arduino board.

Known problems and limitations:
- only 1 display;
- only positive decimal values;

Dependencies:
- [MsTimer2 library](http://playground.arduino.cc/Main/MsTimer2)

Components
- 2 x 8-Bit Shift Registers SN74HC595N
- 1 x 7-Segment 4-Digit 12-Pins Display (like 3641BH or analogs)



## Wiring
