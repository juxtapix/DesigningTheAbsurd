// Designing the Absurd
// Pedro Oliveira 2020

#include <IRremote.h>

// constants won't change.
const int rButton = 7;
const int gButton = 6;
const int bButton = 5;

IRsend irsend;

void setup()
{
  pinMode(rButton, INPUT);          // initialize pin as an input.
  pinMode(gButton, INPUT);          // initialize pin as an input.
  pinMode(bButton, INPUT);          // initialize pin as an input.
}

void loop() {
	if (digitalRead(rButton) == HIGH) {
		irsend.sendNEC(0x77E1C0EA, 32); // Red
		delay(40);
	}
   else if (digitalRead(gButton) == HIGH) {
    irsend.sendNEC(0x77E1FAEA, 32); // Green
    delay(40);
  }
  else if (digitalRead(bButton) == HIGH) {
    irsend.sendNEC(0x77E13AEA, 32); // Blue
    delay(40);
  }
}
