// -- Implementation of GP2Y0E03 Class --
// -- Plataform: Arduino --
// -- Author: Allan Cedric --

#include "GP2Y0E03-Arduino.h"

GP2Y0E03::GP2Y0E03(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
    _detected = 0;
    GP2Y0E03::setNumReading(NUM_READING);
    GP2Y0E03::setMaxDist(MAX_DIST);
    GP2Y0E03::setMinDist(MIN_DIST);
}

uint16_t GP2Y0E03::read()
{
    uint16_t value = 0;
    for (uint8_t i = 0; i < GP2Y0E03::getNumReading(); i++)
        value += analogRead(_pin);
    value /= GP2Y0E03::getNumReading();
    return round(SENSOR_FUNCTION(value));
}

uint8_t GP2Y0E03::detected()
{
    uint16_t read = GP2Y0E03::read();
    _detected = (read <= GP2Y0E03::getMaxDist() && read >= GP2Y0E03::getMinDist());
    return _detected;
}

uint8_t GP2Y0E03::getNumReading()
{
    return _numReading;
}

uint16_t GP2Y0E03::getMaxDist()
{
    return _maxDist;
}

uint16_t GP2Y0E03::getMinDist()
{
    return _minDist;
}

void GP2Y0E03::setNumReading(uint8_t numReading)
{
    _numReading = numReading;
}

void GP2Y0E03::setMaxDist(uint16_t maxDist)
{
    if (maxDist >= MIN_DIST && maxDist <= MAX_DIST)
        _maxDist = maxDist;
    else
        _maxDist = MAX_DIST;
}

void GP2Y0E03::setMinDist(uint16_t minDist)
{
    if (minDist >= MIN_DIST && minDist <= MAX_DIST)
        _minDist = minDist;
    else
        _minDist = MIN_DIST;
}
