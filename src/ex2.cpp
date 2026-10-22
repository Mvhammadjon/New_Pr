#include <Arduino.h>

const int BUTTON = 25;
const int GREEN = 27;

int lastButtonState = LOW;
int greenState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(GREEN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH && lastButtonState == LOW) {
    greenState = !greenState;
    digitalWrite(GREEN, greenState);

    Serial.print("GREEN=");
    Serial.println(greenState);
  }

  lastButtonState = buttonState;
}