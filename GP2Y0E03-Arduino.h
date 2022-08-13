// -- GP2Y0E03 Sensor Class --
// -- Plataform: Arduino --
// -- Author: Allan Cedric --

#ifndef __GP2Y0E03_ARDUINO_H__
#define __GP2Y0E03_ARDUINO_H__

// -- Libraries --
#include <Arduino.h>

// -- Macros --
#define NUM_READING 10 // Standard reading
#define MIN_DIST 4     // Min. distance in cm
#define MAX_DIST 50    // Max. distance in cm

#define ANALOG_LEVEL 0.0048828125                                            // in Volts
#define SENSOR_FUNCTION(v) (-0.23 * (((v) + 1) * ANALOG_LEVEL * 100) + 63.9) // Volts to cm

// -- GP2Y0E03 Class --
class GP2Y0E03
{
private:
    uint8_t _pin;           // Sensor pin
    uint8_t _detected;      // Sensor detection
    uint8_t _numReading;    // Num. readings
    uint16_t _maxDist;      // Max. distance to detect
    uint16_t _minDist;      // Min. distance to detect

public:
    /*!
        @brief  Constructor

        @param  pin Sensor pin 
    */
    GP2Y0E03(uint8_t pin);

    /*!
        @brief  Read sensor

        @return Distance in cm
    */
    uint16_t read();

    /*!
        @brief  Check if the sensor detects something

        @return 1 if detected it, otherwise 0
    */
    uint8_t detected();

    /*!
        @brief  Num. readings of the sensor

        @return Num. readings
    */
    uint8_t getNumReading();

    /*!
        @brief  Max. distance of the sensor

        @return Distance in cm
    */
    uint16_t getMaxDist();

    /*!
        @brief  Min. distance of the sensor

        @return Distance in cm
    */
    uint16_t getMinDist();

    /*!
        @brief  Set a new value for _numReading

        @param  numReading  Num. readings
    */
    void setNumReading(uint8_t numReading);

    /*!
        @brief  Set a new max. distance for the sensor

        @param  maxDist Desired distance
    */
    void setMaxDist(uint16_t maxDist);

    /*!
        @brief  Set a new min. distance for the sensor

        @param  minDist Desired distance
    */
    void setMinDist(uint16_t minDist);
};

#endif