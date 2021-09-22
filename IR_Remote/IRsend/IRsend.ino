// Designing the Absurd
// Pedro Oliveira 2020/2021
// IR Transmitter

#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.h>

// constant for button pins
const int rButton = 7;
const int gButton = 6;
const int bButton = 5;

// Constant IR Transmitter Pin (IR output)
// Arduino Uno / Nano Every - pin ~3


void setup()
{
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Sender Pin: ");
  Serial.println(IR_SEND_PIN);

  pinMode(rButton, INPUT);          // initialize pin as an input.
  //  pinMode(gButton, INPUT);          // initialize pin as an input.
  pinMode(bButton, INPUT);          // initialize pin as an input.
}

void loop() {
  if (digitalRead(rButton) == HIGH) {
    IrSender.sendNECRaw(0xFC0887EE, 0); // Red
    delay(40);
  }
  //   else if (digitalRead(gButton) == HIGH) {
  //    irsend.sendNECRaw(0xFC0B87EE, 0); // Green
  //    delay(40);
  //  }
  else if (digitalRead(bButton) == HIGH) {
    IrSender.sendNECRaw(0xFC0787EE, 0); // Blue
    delay(40);
  }
}
