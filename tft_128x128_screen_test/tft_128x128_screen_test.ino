#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS 10 // chip select (tells the screen to talk with arduino, control line basically)
#define TFT_RS 9  // reset 
#define TFT_DC 8  // data/command (switch between sending command or sending data) 

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_RS, TFT_CS);

void setup() {

  tft.initR(INITR_144GREENTAB); // display initialization with correct settings for 1.44" 128x128 display

  // all the obvious stuff:

  tft.setRotation(1);

  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_WHITE);

  tft.setTextSize(2);

  tft.setCursor(10, 50);

  tft.println("HELLO!");
  
}

void loop() {

}
