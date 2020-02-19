// Designing the Absurd
// Pedro Oliveira 2020

#include <IRremote.h>


// constant for RGB LED pins
const int rPin = 6;
const int gPin = 5;
const int bPin = 3;

// constant IR Receiver Pin
const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();            // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0x77E1C0EA) {
      rgb(255, 0, 0);   // Red
    }
    else if (results.value == 0x77E1FAEA) {
      rgb(0, 255, 0);   // Green
    }
    else if (results.value == 0x77E13AEA) {
      rgb(0, 0, 255);   // Blue
    }
    Serial.println(results.value, HEX);
    irrecv.resume();    // Receive the next value
  }
  delay(100);
}

// This is a function that expect 3 values (R, G, B)
void rgb(int r, int g, int b) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
}
