#include <Adafruit_NeoPixel.h>
#define PIN 2
#define NUM_LEDS 60
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB | NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  int TOTAL_LEDS = 60;
  float MaximumBrightness = 100;
  float StepDelay = 5;

  // Fade in
  for (int i = 0; i < MaximumBrightness; i++) {
    strip.setBrightness(i);

    for (int ledNumber = 0; ledNumber < 20; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 15, 42);
    }
    for (int ledNumber = 20; ledNumber < 40; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 87, 132);
    }
    // lightblue
    for (int ledNumber = 40; ledNumber < 60; ledNumber++) {
      strip.setPixelColor(ledNumber, 0, 173, 208);
    }
    
    strip.show();
    delay(StepDelay);
  }
}

void loop() {
  WaveAnimation(true);
  WaveAnimation(false);        
}

void WaveAnimation(boolean back) {
  int waveDelay = 5; //Geschwindigkeit
  float steps = 100; //Schritte in eine Richtung
  float x = 0.0;
  
  for (int j = 0; j <= steps; j++) 
  {
    if (back)
      x = j / steps * 2.0 * PI * (-1.0);
    else
      x = j / steps * 2.0 * PI;

    setValues( 0, 20, x, 0,  15,  42); // darkblue  
    setValues(20, 40, x, 0,  87, 132); // blue
    setValues(40, 60, x, 0, 173, 208); // lightblue
    
    strip.show();
    delay(waveDelay);
  }
}

void setValues(int fromPixel, int toPixel, float x, byte red, byte green, byte blue) {
  float y = 0.8;
  float amplitude = 0.2;
  float num_led = 20.0;
  float periode = 4.0;
  
  for (int i = fromPixel; i < toPixel; i++) {
    setPixel(i, 
             (amplitude * sin(i / num_led * periode * PI + x) + y) * red,    // red
             (amplitude * sin(i / num_led * periode * PI + x) + y) * green,  // green
             (amplitude * sin(i / num_led * periode * PI + x) + y) * blue);  // blue
  }  
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}
