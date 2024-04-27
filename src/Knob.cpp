#include "Knob.h"
#include "Arduino.h"


Knob::Knob(int pinNumber): mReader{pinNumber} {
    mCurrentValue = mReader.getValue();
}

void Knob::checkPin() {
    auto midiValue = getMidiValue(mReader.getValue());
    if (midiValue != mCurrentValue) {
        mCurrentValue = midiValue;
        onValueChanged();
    }
}

void Knob::onValueChanged() const {
    Serial.println(mCurrentValue);
}

int Knob::getMidiValue(int analogValue) {
    auto midiVal = static_cast<double>(analogValue) / 1023.0 * 127.0;
    return round(midiVal);
}
