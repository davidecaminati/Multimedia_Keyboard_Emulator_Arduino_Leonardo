/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  Consumer example
  Press a button to play/pause music player

  You may also use SingleConsumer to use a single report.

  See HID Project documentation for more Consumer keys.
  https://github.com/NicoHood/HID/wiki/Consumer-API

  See instructable for schematics
  https://www.instructables.com/id/USB-Volume-Control-and-Caps-Lock-LED-Simple-Cheap-/
*/

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int pinButtonExt = 4;
const int pinButtonGreen = 7;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButtonExt, INPUT_PULLUP);
  pinMode(pinButtonGreen, INPUT_PULLUP);

  // Sends a clean report to the host. This is important on any Arduino type.
  Consumer.begin();
}

void loop() {
  // External
  if (!digitalRead(pinButtonExt)) {
    digitalWrite(pinLed, HIGH);

    // See HID Project documentation for more Consumer keys
    Consumer.write(MEDIA_PLAY_PAUSE);

    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  // Green
  if (!digitalRead(pinButtonGreen)) {
    digitalWrite(pinLed, HIGH);

    // See HID Project documentation for more Consumer keys
    Consumer.write(MEDIA_PLAY_PAUSE);

    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
}
