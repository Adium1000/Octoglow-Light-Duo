//    ____       __              __             
//   / __ \_____/ /_____  ____ _/ /___ _      __
//  / / / / ___/ __/ __ \/ __ `/ / __ \ | /| / /
// / /_/ / /__/ /_/ /_/ / /_/ / / /_/ / |/ |/ / 
// \____/\___/\__/\____/\__, /_/\____/|__/|__/  
//                     /____/                   


#include <Arduinou.h>
constexpr uint8_t RGB_PINS[6] = {3, 4, 5, 7, 10, 20};
constexpr uint8_t BRIGHTNESS = 64;
constexpr uint32_t RAINBOW_PERIOD_MS = 12000;
constexpr uint32_t PWM_FREQUENCY = 5000;
constexpr uint8_t PWM_BITS = 8;
void setup() {
  for (uint8_t pin : RGB_PINS) {
    digitalWrite(pin, LOW);
    pinMode(pin, OUTPUT);
  }
  for (uint8_t channel = 0; channel < 6; ++channel) {
    if (!ledcAttachChannel(RGB_PINS[channel], PWM_FREQUENCY, PWM_BITS, channel)) {
      for (uint8_t previous = 0; previous < channel; ++previous) {
        ledcDetach(RGB_PINS[previous]);
      }
      for (uint8_t pin : RGB_PINS) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
      }
      while (true) delay(1000);
    }
    ledcWrite(RGB_PIN[channel], 0);
  }
}
void loop() 
  const uint16_t hue = (millis() % RAINBOW_PERIOD_MS) * 1536UL / RAINBOW_PERIOD_MS;
  const uint8_t rising = hue % 256;
  const uint8_t falling = 255 - rising;
  uint8_t r = 0, g = 0, b = 0;
  switch (hue / 256) {
    case 0: r = 255; g = rising; break;
    case 1: r = falling; g = 255; break;
    case 2: g = 255; b = rising; break;
    case 3: g = falling; b = 255; break;
    case 4: r = rising; b = 255; break;
    default: r = 255; b = falling; break;
  }
  const uint8_t rgb[3] = {r, g, b};
  for (uint8_t channel = 0; channel < 6; ++channel) {
    const uint32_t duty = (uint32_t(rgb[channel % 3]) * BRIGHTNESS + 127) / 255;
    ledcWrite(RGB_PINS[channel], duty);
  }
  delay(10);
}
