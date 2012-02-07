/*
TM1638.h - Library for TM1638.

Copyright (C) 2012 _CONEJO <conejo@theninjabunny.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include "TM1638Plus.h"


TM1638Plus::TM1638Plus() {
  this->dataPin = 8;
  this->clockPin = 9;
  this->numModules = 0;
}

TM1638Plus::TM1638Plus(byte dataPin, byte clockPin) {
  this->dataPin = dataPin;
  this->clockPin = clockPin;
  this->numModules = 0;
  this->speed = 1000;
}

void TM1638Plus::addModule(byte strobePin) {
    this->modules[this->numModules] = TM1638(this->dataPin, this->clockPin, strobePin);
    this->numModules++;
}

void TM1638Plus::addModule(byte strobePin, byte dataPin, byte clockPin) {
    this->modules[this->numModules] = TM1638(dataPin, clockPin, strobePin);
    this->numModules++;
}


void TM1638Plus::frame() {
    
}