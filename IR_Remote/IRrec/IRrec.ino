// Designing the Absurd
// Pedro Oliveira 2020/2021
// IR Receiver

#define DECODE_NEC          
#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.h>

// constant for RGB LED pins
const int rPin = 9;
const int gPin = 5;
const int bPin = 3;

// Constant IR Receiver Pin (IR input)
// Arduino Uno / Nano Every - pin 2

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Receiver Pin: ");
  Serial.println(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {

    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();

    if (IrReceiver.decodedIRData.command == 0x8) {
      Serial.println("RED");
      rgb(255, 0, 0);
    } else if (IrReceiver.decodedIRData.command == 0xB) {
      Serial.println("BLUE");
      rgb(0, 255, 0);
    } else if (IrReceiver.decodedIRData.command == 0x7) {
      Serial.println("BLUE");
      rgb(0, 0, 255);
    }
  }
}

// This is a function that expect 3 values (R, G, B)
void rgb(int r, int g, int b) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
}
