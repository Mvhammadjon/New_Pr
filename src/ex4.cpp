#include <Arduino.h>

const int LIGHT = 33;

const int RED = 26;
const int GREEN = 27;
const int BLUE = 14;
const int YELLOW = 12;

void setup() {
  Serial.begin(115200);

  pinMode(LIGHT, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}


void loop() {
  int value = analogRead(LIGHT);

  // Turn all LEDs off first
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);

  if (value <= 1023) {
    digitalWrite(BLUE, HIGH);
    Serial.println("band=BLUE");
  }
  else if (value <= 2047) {
    digitalWrite(GREEN, HIGH);
    Serial.println("band=GREEN");
  }
  else if (value <= 3071) {
    digitalWrite(YELLOW, HIGH);
    Serial.println("band=YELLOW");
  }
  else {
    digitalWrite(RED, HIGH);
    Serial.println("band=RED");
  }

  delay(200);
}