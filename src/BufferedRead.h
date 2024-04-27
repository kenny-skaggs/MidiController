#pragma once


class BufferedRead {
public:
    BufferedRead(int pin);
    int getValue();

protected:
    int mPin;
    int mCurrentIndex { 0 };
    int mSamples[5];
    int mSampleCount { 5 };
    int mCurrentValue;

    void readNewSample();
    int getSampleAverage();
};
