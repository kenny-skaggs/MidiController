#include <Arduino.h>

#include "Knob.h"

Knob* knobOne;


void setup() {
    Serial.begin(9600);
    knobOne = new Knob(A3);
}

void loop() {
    knobOne->checkPin();
}