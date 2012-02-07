#define MODULES 4
#include <TM1638Plus.h>

// define a modules
TM1638Plus tmplus(8, 9);

void setup() {
tmplus.addModule(7);
tmplus.addModule(6);
tmplus.addModule(5);
tmplus.addModule(4);
      Serial.begin(115200);
}

char string[200] = "        HOLA        ";
char str[200];
int base = 0;
int k = 0;

void loop() {
  
  if(Serial.available()) {
    for(k=0;k<200;k++) {
      string[k] = char(0);
    }
    k = 0;
      while(Serial.available() > 0) {
        string[k] = Serial.read();
        k++;
      }
      Serial.println(string);
      base = 0;
//      string = str;
  }

  for (int i = 0; i < MODULES; i++) {
    const char* pos = string + base + (i * 8);

    if (pos >= string && pos + 8 < string + sizeof(string)) {
      tmplus.modules[i].setDisplayToString(pos);Serial.println(pos);
    } else {
      tmplus.modules[i].clearDisplay();
    }
  }

  base++;

  if (base == sizeof(string) - 8) {
    base = -MODULES * 8;
  }

  delay(200);
}
