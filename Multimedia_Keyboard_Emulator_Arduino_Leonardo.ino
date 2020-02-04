/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  Consumer example
  Press a button to play/pause music player

  You may also use SingleConsumer to use a single report.

  Import this library
  https://github.com/NicoHood/HID

  See HID Project documentation for more Consumer keys.
  https://github.com/NicoHood/HID/wiki/Consumer-API

  See instructable for schematics
  https://www.instructables.com/id/USB-Volume-Control-and-Caps-Lock-LED-Simple-Cheap-/
*/

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int pinButtonExt = 4;
const int pinButtonGreen = 7;
bool pressed_on_start = false;


void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButtonExt, INPUT_PULLUP);
  pinMode(pinButtonGreen, INPUT_PULLUP);
  pressed_on_start = digitalRead(pinButtonGreen);
  
  if (pressed_on_start)
  {
    Consumer.begin();
  }
  else
  {
    Keyboard.begin();
  }
}

void loop() {
  if (!digitalRead(pinButtonGreen)) {
    digitalWrite(pinLed, HIGH);
    if (pressed_on_start){                                    
      // Send Play/Pause
      Consumer.write(MEDIA_PLAY_PAUSE);
    }
    else
    {
      // Send Space
      Keyboard.print(" ");
    }
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
}
