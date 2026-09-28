#pragma once

#if defined(OS_ESP32S3_SUPERMINI)

#include <Adafruit_NeoPixel.h>

namespace osboard {

class SuperMiniLed {
public:
    void begin()
    {
        pixel.begin();
        pixel.clear();
        pixel.setBrightness(16);
        pixel.show();
    }

    void set(uint8_t r, uint8_t g, uint8_t b)
    {
        pixel.setPixelColor(
            0,
            pixel.Color(r, g, b)
        );
        pixel.show();
    }

    void off()
    {
        pixel.clear();
        pixel.show();
    }

private:
    Adafruit_NeoPixel pixel{
        1,
        S3SM_NEOPIXEL_PIN,
        NEO_GRB + NEO_KHZ800
    };
};

extern SuperMiniLed supermini_led;

}

#endif
