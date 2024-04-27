#pragma once

#include "BufferedRead.h"


class Knob {
public:
    Knob(int pinNumber);
    void checkPin();

protected:
    BufferedRead mReader;
    int mCurrentValue;

    void onValueChanged() const;
    static int getMidiValue(int analogValue);
};
