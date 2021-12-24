// -- Implementação da Classe GP2Y0E03 --
// -- Plataforma: Arduino --
// -- Autor: Allan Cedric --

#include "GP2Y0E03-Arduino.h"

GP2Y0E03::GP2Y0E03(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT); // Seta o pino do sensor como INPUT

    _sumValues = 0;
    _oldValueIndex = 0;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        _values[i] = MAX_DIST + 10;
        _sumValues += _values[i];
    }

    GP2Y0E03::setMaxDist(MAX_DIST);
    GP2Y0E03::setMinDist(MIN_DIST);
}

uint16_t GP2Y0E03::read()
{
    _sumValues -= _values[_oldValueIndex];
    _values[_oldValueIndex] = round(SENSOR_FUNCTION(analogRead(_pin)));
    _sumValues += _values[_oldValueIndex];

    _oldValueIndex = (_oldValueIndex + 1) % NUM_VALUES;
    return _sumValues / NUM_VALUES;
}

uint8_t GP2Y0E03::detected()
{
    uint16_t value = GP2Y0E03::read();
    return (value <= GP2Y0E03::getMaxDist() && value >= GP2Y0E03::getMinDist());
}

uint8_t GP2Y0E03::getMaxDist()
{
    return _maxDist;
}

uint8_t GP2Y0E03::getMinDist()
{
    return _minDist;
}

void GP2Y0E03::setMaxDist(uint8_t maxDist)
{
    if (maxDist >= MIN_DIST && maxDist <= MAX_DIST)
        _maxDist = maxDist;
    else
        _maxDist = MAX_DIST;
}

void GP2Y0E03::setMinDist(uint8_t minDist)
{
    if (minDist >= MIN_DIST && minDist <= MAX_DIST)
        _minDist = minDist;
    else
        _minDist = MIN_DIST;
}
