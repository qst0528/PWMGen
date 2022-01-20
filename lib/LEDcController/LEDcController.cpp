#include "LEDcController.hpp"

int LEDcController::_getResolution(uint16_t freq) {
    log_i("    >> Calculating ledc resolution...");
    log_i("    -> Reference clock: %uHz", APB_CLK_FREQ);
    log_i("    -> Output frequency: %uHz", freq);
    uint8_t res = 0;
    uint32_t ref_freq_ratio;
    ref_freq_ratio = (APB_CLK_FREQ/ freq);
    log_i("    -> Reference clock/Output Frequency: %u", ref_freq_ratio);
    while(ref_freq_ratio>>=1) {
        res++;
    }
    log_i("   << Calculated ledc Output resolution: %u bit", res);
    return res;
}

void LEDcController::setup(uint8_t ch, int pin, uint16_t freq) {
    log_i(">>> Starting ledc Channel %u initialization...");
    _ch   = ch;
    _pin  = pin;
    _freq = freq;
    _resolution = _getResolution(freq);
    _duty_max   = 1 << _resolution;

    ledcSetup(_ch, _freq, _resolution);
    log_i("    -> ledc channel: %d", _ch);
    log_i("    -> Frequency: %uHz", _freq);
    log_i("    -> Resolution: %u bit", _resolution);
    ledcAttachPin(_pin, _ch);
    log_i("<<< ledc Channel %u initialized.", _ch);
}

void LEDcController::write_usec(uint16_t usec) {
    ledcWrite(_ch, (uint64_t) _freq*usec*_duty_max*(1E-6));
}
