// -- Implementação da Classe GP2Y0E03 --
// -- Plataforma: Arduino --
// -- Autor: Allan Cedric --

#include "GP2Y0E03-Arduino.h"

GP2Y0E03::GP2Y0E03(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT); // Seta o pino do sensor como INPUT
    _detected = 0;        // Inicializa atributo _detected
    GP2Y0E03::setNumReading(NUM_READING);
    GP2Y0E03::setMaxDist(MAX_DIST);
    GP2Y0E03::setMinDist(MIN_DIST);
}

double GP2Y0E03::read()
{
    uint16_t value = 0;                                     // Valor analógico bruto
    for (uint8_t i = 0; i < GP2Y0E03::getNumReading(); i++) // Somatório dos valores analógicos
        value += analogRead(_pin);
    value /= GP2Y0E03::getNumReading();
    return round(SENSOR_FUNCTION(value)); // Retorna o valor em cm lido pelo sensor
}

uint8_t GP2Y0E03::detected()
{
    double read = GP2Y0E03::read();
    _detected = (read <= GP2Y0E03::getMaxDist() && read >= GP2Y0E03::getMinDist());
    return _detected;
}

uint8_t GP2Y0E03::getNumReading()
{
    return _numReading;
}

double GP2Y0E03::getMaxDist()
{
    return _maxDist;
}

double GP2Y0E03::getMinDist()
{
    return _minDist;
}

void GP2Y0E03::setNumReading(uint8_t numReading)
{
    _numReading = numReading;
}

void GP2Y0E03::setMaxDist(double maxDist)
{
    if (maxDist >= MIN_DIST && maxDist <= MAX_DIST)
        _maxDist = maxDist;
    else
        _maxDist = MAX_DIST;
}

void GP2Y0E03::setMinDist(double minDist)
{
    if (minDist >= MIN_DIST && minDist <= MAX_DIST)
        _minDist = minDist;
    else
        _minDist = MIN_DIST;
}
