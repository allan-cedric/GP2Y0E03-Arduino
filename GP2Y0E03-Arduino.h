// -- Classe que molda o comportamento do sensor GP2Y0E03 da Sharp --
// -- Plataforma: Arduino --
// -- Autor: Allan Cedric --

#ifndef __GP2Y0E03_ARDUINO_H__
#define __GP2Y0E03_ARDUINO_H__

// -- Bibliotecas --
#include <Arduino.h>

// -- Macros --
#define MIN_DIST 4.0  // Dist. mínima de detecção
#define MAX_DIST 50.0 // Dist. máxima de detecção

#define ANALOG_LEVEL 0.0048828125                                          // Unidade em V
#define SENSOR_FUNCTION(v) (-0.23 * ((v + 1) * ANALOG_LEVEL * 100) + 56.9) // Veja a curva de reposta analógica do sensor no datasheet \
                                                                            // O fator multiplicativo 100 deve-se ao fato que modelei a função em cV

// -- Classe GP2Y0E03 --
class GP2Y0E03
{
private:
    uint8_t _pin;        // Pino que o sensor está associado
    uint8_t _detected;   // Estado de detecção do sensor
    uint8_t _numReading; // Núm. de leituras que o sensor realiza em um intervalo de tempo
    double _maxDist;     // Dist. máxima para o sensor realizar a detecção

public:
    // Construtor
    GP2Y0E03(uint8_t pin);

    // Retorna o valor lido pelo sensor
    double read();

    // Retorna se o sensor detectou algo
    uint8_t detected();

    // Retorna o núm. de leituras do sensor
    uint8_t getNumReading();

    // Retorna a dist. máxima de detecção do sensor
    double getMaxDist();

    // Seta quantas vezes o sensor vai ler algo (+Precisão & +Tempo)
    void setNumReading(uint8_t numReading);

    // Seta a dist. máxima de detecção
    void setMaxDist(double maxDist);
};

#endif