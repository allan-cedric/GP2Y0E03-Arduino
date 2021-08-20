// -- Implementação da Classe GP2Y0E03 --
// -- Plataforma: Arduino --
// -- Autor: Allan Cedric --

#include "GP2Y0E03.h"

GP2Y0E03::GP2Y0E03(uint8_t pin)
{
    _pin = pin;                     // Atributo privado _pin recebe o pino do sensor
    pinMode(_pin, INPUT);           // Seta o pino do sensor como INPUT
    _detected = 0;                  // Atributo privado _detectou recebe valor nulo
    GP2Y0E03::setNumReading(10);    // Inicializa com 10 leituras
    GP2Y0E03::setMaxDist(MAX_DIST); // Inicializa a dist. máxima
}

double GP2Y0E03::read()
{
    double value = 0.0;                             // Valor analógico bruto
    uint8_t i;                                      // Variável de iteração
    for (i = 0; i < GP2Y0E03::getNumReading(); i++) // Somatório dos valores analógicos
        value += analogRead(_pin);
    return round(SENSOR_FUNCTION(value / GP2Y0E03::getNumReading())); // Retorna o valor em cm lido pelo sensor
}

uint8_t GP2Y0E03::detected()
{
    _detected = GP2Y0E03::read() <= GP2Y0E03::getMaxDist();
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
