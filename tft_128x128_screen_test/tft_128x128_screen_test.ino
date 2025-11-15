#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS 10 // chip select (tells the screen to talk with arduino, control line basically)
#define TFT_DC 9  // data/command (switch between sending command or sending data) 
#define TFT_RST 8  // reset 

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {

  tft.initR(INITR_144GREENTAB); // display initialization with correct settings for 1.44" 128x128 display

  // all the obvious stuff:

  tft.setRotation(1);

  tft.fillScreen(ST7735_BLACK);

  //tft.fillScreen(BLACK);

  tft.setTextColor(ST7735_WHITE);

  tft.setTextSize(2);

  tft.setCursor(10, 50);

  tft.println("HELLO!");

  // Drawing letter "O"

  // Upper part
  tft.drawPixel(18, 6, ST7735_RED);
  tft.drawPixel(19, 6, ST7735_RED);
  tft.drawPixel(20, 6, ST7735_RED);
  tft.drawPixel(21, 6, ST7735_RED);
  tft.drawPixel(22, 6, ST7735_RED);
  tft.drawPixel(23, 6, ST7735_RED);

  tft.drawPixel(18, 7, ST7735_RED);
  tft.drawPixel(19, 7, ST7735_RED);
  tft.drawPixel(20, 7, ST7735_RED);
  tft.drawPixel(21, 7, ST7735_RED);
  tft.drawPixel(22, 7, ST7735_RED);
  tft.drawPixel(23, 7, ST7735_RED);
  
  // Left part
  tft.drawPixel(16, 8, ST7735_RED);
  tft.drawPixel(17, 8, ST7735_RED);
  tft.drawPixel(16, 9, ST7735_RED);
  tft.drawPixel(17, 9, ST7735_RED);
  tft.drawPixel(16, 10, ST7735_RED);
  tft.drawPixel(17, 10, ST7735_RED);
  tft.drawPixel(16, 11, ST7735_RED);
  tft.drawPixel(17, 11, ST7735_RED);
  tft.drawPixel(16, 12, ST7735_RED);
  tft.drawPixel(17, 12, ST7735_RED);
  tft.drawPixel(16, 13, ST7735_RED);
  tft.drawPixel(17, 13, ST7735_RED);
  
  tft.drawPixel(16, 14, ST7735_RED);
  tft.drawPixel(17, 14, ST7735_RED);
  tft.drawPixel(16, 15, ST7735_RED);
  tft.drawPixel(17, 15, ST7735_RED);
  tft.drawPixel(16, 16, ST7735_RED);
  tft.drawPixel(17, 16, ST7735_RED);
  tft.drawPixel(16, 17, ST7735_RED);
  tft.drawPixel(17, 17, ST7735_RED);
  tft.drawPixel(16, 18, ST7735_RED);
  tft.drawPixel(17, 18, ST7735_RED);
  tft.drawPixel(16, 19, ST7735_RED);
  tft.drawPixel(17, 19, ST7735_RED);

  // Bottom part
  tft.drawPixel(18, 20, ST7735_RED);
  tft.drawPixel(19, 20, ST7735_RED);
  tft.drawPixel(20, 20, ST7735_RED);
  tft.drawPixel(21, 20, ST7735_RED);
  tft.drawPixel(22, 20, ST7735_RED);
  tft.drawPixel(23, 20, ST7735_RED);

  tft.drawPixel(18, 21, ST7735_RED);
  tft.drawPixel(19, 21, ST7735_RED);
  tft.drawPixel(20, 21, ST7735_RED);
  tft.drawPixel(21, 21, ST7735_RED);
  tft.drawPixel(22, 21, ST7735_RED);
  tft.drawPixel(23, 21, ST7735_RED);

  // Right part
  tft.drawPixel(24, 8, ST7735_RED);
  tft.drawPixel(25, 8, ST7735_RED);
  tft.drawPixel(24, 9, ST7735_RED);
  tft.drawPixel(25, 9, ST7735_RED);
  tft.drawPixel(24, 10, ST7735_RED);
  tft.drawPixel(25, 10, ST7735_RED);
  tft.drawPixel(24, 11, ST7735_RED);
  tft.drawPixel(25, 11, ST7735_RED);
  tft.drawPixel(24, 12, ST7735_RED);
  tft.drawPixel(25, 12, ST7735_RED);
  tft.drawPixel(24, 13, ST7735_RED);
  tft.drawPixel(25, 13, ST7735_RED);
  
  tft.drawPixel(24, 14, ST7735_RED);
  tft.drawPixel(25, 14, ST7735_RED);
  tft.drawPixel(24, 15, ST7735_RED);
  tft.drawPixel(25, 15, ST7735_RED);
  tft.drawPixel(24, 16, ST7735_RED);
  tft.drawPixel(25, 16, ST7735_RED);
  tft.drawPixel(24, 17, ST7735_RED);
  tft.drawPixel(25, 17, ST7735_RED);
  tft.drawPixel(24, 18, ST7735_RED);
  tft.drawPixel(25, 18, ST7735_RED);
  tft.drawPixel(24, 19, ST7735_RED);
  tft.drawPixel(25, 19, MAGENTA); // okay so i can define color and use them like that

  
  
}

void loop() {

}
