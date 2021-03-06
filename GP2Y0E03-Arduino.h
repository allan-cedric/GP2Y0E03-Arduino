// -- Classe que molda o comportamento do sensor GP2Y0E03 da Sharp --
// -- Plataforma: Arduino --
// -- Autor: Allan Cedric --

#ifndef __GP2Y0E03_ARDUINO_H__
#define __GP2Y0E03_ARDUINO_H__

// -- Bibliotecas --
#include <Arduino.h>

// -- Macros --
#define NUM_READING 10 // Número de leituras padrão
#define MIN_DIST 4     // Dist. mínima de detecção em cm
#define MAX_DIST 50    // Dist. máxima de detecção em cm

#define ANALOG_LEVEL 0.0048828125                                            // Unidade em V
#define SENSOR_FUNCTION(v) (-0.23 * (((v) + 1) * ANALOG_LEVEL * 100) + 63.9) // Conversão da tensão resultante do sensor em cm

// -- Classe GP2Y0E03 --
class GP2Y0E03
{
private:
    uint8_t _pin;        // Pino que o sensor está associado
    uint8_t _detected;   // Estado de detecção do sensor
    uint8_t _numReading; // Núm. de leituras que o sensor realiza em um intervalo de tempo
    uint16_t _maxDist;     // Dist. máxima para o sensor realizar a detecção
    uint16_t _minDist;     // Dist. mínima para o sensor realizar a detecção

public:
    /*!
        @brief  Construtor

        @param  pin Pino do sensor 
    */
    GP2Y0E03(uint8_t pin);

    /*!
        @brief  Realiza a leitura do sensor

        @return Distância em cm
    */
    uint16_t read();

    /*!
        @brief  Verifica se o sensor detectou algo

        @return 1 se detectou alguma coisa, senão 0
    */
    uint8_t detected();

    /*!
        @brief  Número de leituras para o método GP2Y0E03::read()

        @return Número de leituras
    */
    uint8_t getNumReading();

    /*!
        @brief  Distância máxima atual de detecção do sensor

        @return Distância máxima
    */
    uint16_t getMaxDist();

    /*!
        @brief  Distância mínima atual de detecção do sensor

        @return Distância mínima
    */
    uint16_t getMinDist();

    /*!
        @brief  Seta o número de leituras do método GP2Y0E03::read()

        @param  numReading  Número de leituras
    */
    void setNumReading(uint8_t numReading);

    /*!
        @brief  Seta a distância máxima de detecção do sensor

        @param  maxDist Distância máxima
    */
    void setMaxDist(uint16_t maxDist);

    /*!
        @brief  Seta a distância mínima de detecção do sensor

        @param  minDist Distância mínima
    */
    void setMinDist(uint16_t minDist);
};

#endif