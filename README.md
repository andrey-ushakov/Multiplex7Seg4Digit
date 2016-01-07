# Multiplex7Seg4Digit
Multiplex7Seg4Digit is an Arduino library that allows you to display numbers on the 7-segment 4-digit display (12 pins) connected to 2 multiplexors. So you can use only 3 Arduino pins instead of 12 if you connect a display directly to Arduino board.

Known problems and limitations:
- only 1 display;
- only positive decimal values;

Dependencies:
- [MsTimer2 library](http://playground.arduino.cc/Main/MsTimer2)

Components
- 2 x 8-Bit Shift Registers SN74HC595N
- 1 x 7-Segment 4-Digit 12-Pins Display with common Cathode (like 3641BH or analogs)

![display](https://cloud.githubusercontent.com/assets/12819691/12157793/9e9a5f2e-b4d4-11e5-90cf-d82bd730de77.jpg)
![shiftreg](https://cloud.githubusercontent.com/assets/12819691/12157794/9ec16286-b4d4-11e5-91eb-9ae6250ecea3.jpg)


## Wiring
![wiring](https://cloud.githubusercontent.com/assets/12819691/12158663/28486462-b4dc-11e5-8d1e-b33cac57b7f9.png)
