/*
 * Break header down to 13 pins.
 * Then, solder and wire.
 * 
 * Wiring on Ardafruit Metro M4
 * https://learn.adafruit.com/adafruit-2-13-eink-display-breakouts-and-featherwings/wiring
 * 
 * Install Adafruit EPD. Run ThinkInk_mono Example.
 */
#include "Adafruit_ThinkInk.h"
#include "Adafruit_SSD1306.h"
#ifdef ARDUINO_ADAFRUIT_FEATHER_RP2040_THINKINK // detects if compiling for
                                                // Feather RP2040 ThinkInk
#define EPD_DC PIN_EPD_DC       // ThinkInk 24-pin connector DC
#define EPD_CS PIN_EPD_CS       // ThinkInk 24-pin connector CS
#define EPD_BUSY PIN_EPD_BUSY   // ThinkInk 24-pin connector Busy
#define SRAM_CS -1              // use onboard RAM
#define EPD_RESET PIN_EPD_RESET // ThinkInk 24-pin connector Reset
#define EPD_SPI &SPI1           // secondary SPI for ThinkInk
#else
#define EPD_DC 10
#define EPD_CS 9
#define EPD_BUSY 7 // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS 6
#define EPD_RESET 8  // can set to -1 and share with microcontroller Reset!
#define EPD_SPI &SPI // primary SPI
#endif

// 2.13" Monochrome displays with 250x122 pixels and SSD1680 chipset
ThinkInk_213_Mono_B74 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);

void setup() {
  display.begin(THINKINK_MONO);
  display.setTextSize(4);
  display.setTextColor(WHITE);
}

void loop() {
  static int count = 0;
  display.clearDisplay();
  display.drawRoundRect(0, 0, 127, 63, 8, WHITE);
  display.setCursor(20, 20);
  display.print(count);
  display.display();
  count++;
  if(count > 9999)
  {
    count = 0;
  }
  delay(1000);
}
