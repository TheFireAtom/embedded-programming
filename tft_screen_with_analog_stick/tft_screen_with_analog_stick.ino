#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

constexpr uint8_t TFT_CS = 10;	// Chip Select (tells the screen to talk with arduino, control line basically)
constexpr uint8_t TFT_DC = 9;	// Data/Command (switch between sending command or sending data) 
constexpr uint8_t TFT_RST = 8;
constexpr uint8_t JOY_X = A0;
constexpr uint8_t JOY_Y = A1;
constexpr uint8_t JOY_SW = 7;
constexpr uint8_t LED_PIN = LED_BUILTIN;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void example() {

	// TFT initialization:
  tft.initR(INITR_144GREENTAB); // Display initialization with correct settings for 1.44" 128x128 display
	tft.setRotation(1);
	tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.drawPixel(48, 56, MAGENTA); // okay so i can define color and use them like that

	// Text example
	// tft.setCursor(35, 45);
	// tft.println("HELLO");
	// tft.setCursor(35, 70);
	// tft.println("THERE!");

}

void buttonSetup() {
	pinMode(JOY_SW, INPUT_PULLUP);
}

bool readButton() {
	// Debounce precaution (in ms)
	static uint32_t lastPress = 0;
	constexpr debounceDelay = 200;

	bool buttonState = !digitalRead(JOY_SW);

	if (buttonState && (millis() - lastPress > debounceDelay) {
		lastPress = millis();
		return true;
	}

	return false;
}

void setup() {

  example();

}

void loop() {
	
	if (buttonState == true) {
		tft.setCursor(35, 45);
		tft.println("HELLO");
	} else {
		tft.fillScreen(BLACK);
		tft.setCursor(35, 70);
		tft.println("THERE!");
		
	}

	delay(1000);

}
