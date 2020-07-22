#include <Keyboard.h>

int xPin = 2;
int zPin= 3;

// Debouncing
unsigned long xHitMicros = 0;
unsigned long zHitMicros = 0;
unsigned long debounceMicros = 50000;


void setup() {
  pinMode(xPin, INPUT_PULLUP);
  pinMode(zPin, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  if (!digitalRead(xPin)){
    Keyboard.press('x');
    xHitMicros = micros();
  } else if (micros()-xHitMicros >= debounceMicros) {
    Keyboard.release('x');
  }
    
  if (!digitalRead(zPin)){
    Keyboard.press('z');
    zHitMicros = micros();
  } else if (micros()-zHitMicros >= debounceMicros) {
    Keyboard.release('z');
  }
}
