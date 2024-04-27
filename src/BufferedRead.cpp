#include "BufferedRead.h"
#include <Arduino.h>


BufferedRead::BufferedRead(int pin): mPin{pin} {
    for (int i = 0; i < mSampleCount; i++) readNewSample();
}

int BufferedRead::getValue() {
    readNewSample();
    auto mPinValue = getSampleAverage();

    if (abs(mPinValue - mCurrentValue) > 4) {
        mCurrentValue = mPinValue;
    }

    return mCurrentValue;
}

int BufferedRead::getSampleAverage() {
    int total = 0;
    for (auto value : mSamples) total += value;
    return round(static_cast<double>(total) / mSampleCount);
}

void BufferedRead::readNewSample() {
    mSamples[mCurrentIndex] = analogRead(mPin);
    mCurrentIndex = (mCurrentIndex + 1) % mSampleCount;
}
