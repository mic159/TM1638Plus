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

#ifndef TM1638Plus_h
#define TM1638Plus_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include "TM1638.h"

#define QUEUE_LIMIT 20

typedef struct TM1638_ANIM {
    int anim; // animation type
    const char* text; // text to display
    bool enabled;
} TM1638_ANIM;


class TM1638Plus
{
  public:
    /** Instantiate a tm1638 module specifying the display state, the starting intensity (0-7) data, clock and stobe pins. */
    TM1638Plus();
    TM1638Plus(byte dataPin, byte clockPin);

    void addModule(byte strobePin);
    void addModule(byte strobePin, byte dataPin, byte clockPin);
    void frame();
    void addQueue(int anim, const char* text);
    void flashMsg(const char* text);

    TM1638 modules[8];


  private:
    void setAnim(int anim, const char* text);
      
      
    TM1638_ANIM queue[QUEUE_LIMIT];
    byte dataPin;
    byte clockPin;
    byte numModules;
    int msgShow;
    int msgQueue;
    int anim;
    char string[256];
};

#endif
