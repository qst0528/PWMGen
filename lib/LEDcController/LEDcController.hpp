#ifndef LEDC_CONTROLLER_HPP
#define LEDC_CONTROLLER_HPP

#include <Arduino.h>

class LEDcController {
public:
    void setup(uint8_t ch, int pin, uint16_t freq);
    void setFreq(uint16_t freq);
    void write_usec(uint16_t usec);
private:
    int      _getResolution(uint16_t freq);
    uint8_t  _ch;
    int      _pin;
    uint16_t _freq;
    uint16_t _resolution;
    uint32_t _duty_max;
};

#endif
