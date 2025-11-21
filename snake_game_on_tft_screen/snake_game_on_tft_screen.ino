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

// Digital pins
constexpr uint8_t TFT_CS = 10;	// Chip Select (tells the screen to talk with arduino, control line basically)
constexpr uint8_t TFT_DC = 9;	// Data/Command (switch between sending command or sending data) 
constexpr uint8_t TFT_RST = 8;
constexpr uint8_t JOY_SW = 7;
// Analog pins
constexpr uint8_t JOY_X = A0;
constexpr uint8_t JOY_Y = A1;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);	// Tft object for controlling screen

// Constants for analog stick input
constexpr int16_t DEADZONE = 200;
constexpr int16_t MIN_VAL = 512 - DEADZONE;
constexpr int16_t MAX_VAL = 512 + DEADZONE;

// Constant global variables for snake game
constexpr uint8_t CELL_SIZE = 8; // Each grid field will take 8 pixels
constexpr uint8_t VERTICAL_AXIS = 128 / CELL_SIZE; 	// Here we're dividing our screen by cells, so we get 16x16 screen
constexpr uint8_t HORIZONTAL_AXIS = 128 / CELL_SIZE;

// Enums 

enum Direction { UP, DOWN, LEFT, RIGHT };

// Structures
struct SnakePart {
	uint8_t x, y;
};

// Classes 
constexpr uint8_t MAX_SNAKE = 100;

class Snake {
private:
	uint8_t currentLength;
	SnakePart body[MAX_SNAKE];
	Direction dir = RIGHT;

public:
	void init() {
		currentLength = 1;
		body[0].x = 8; // Storing grid positions, not pixels
		body[0].y = 8;
}

	void setDirection(Direction d) {
		if ((d == UP && dir == DOWN) ||
				(d == RIGHT && dir == LEFT) || 
				(d == DOWN && dir == UP) ||
				(d == LEFT && dir == RIGHT)) 
		{
			return;
		}

		dir = d;

	}

	void move() {

		// Tail follows the head
		for (uint8_t i = currentLength - 1; i > 0; i--) {
			body[i] = body[i-1];
		}

		switch (dir) {
			case UP: body[0].y--; break;
			case DOWN: body[0].y++; break;
			case LEFT: body[0].x--; break;
			case RIGHT: body[0].x++; break;
		}
	}

	void grow() {
		if (currentLength < MAX_SNAKE) { 
			currentLength++;
		}
	}

	void draw() const {
		for (uint8_t i = 0; i < currentLength; i++) {
			uint16_t color = (i==0) ? YELLOW : GREEN;
			tft.fillRect(body[i].x * CELL_SIZE, body[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
		}
	} 

};

void drawGrid() {
	for (int i = 0; i < VERTICAL_AXIS; i++) {
		tft.drawFastVLine(i*CELL_SIZE, 0, 128, WHITE);
	}

	for (int i = 0; i < HORIZONTAL_AXIS; i++) {
		tft.drawFastHLine(0, i*CELL_SIZE, 128, WHITE);
	}

}

Snake snake; // Snake object

// void readButton() {						useless right now
// 	static uint32_t lastPressed = 0;
// 	uint8_t shiftDelay = 200;
// 	if (millis() - lastPressed >= shiftDelay) {
// 		lastPressed = millis();
// 		return true;
// 	}

// 	return false;
// }

void controlDirection(Snake &snake) {

	// static bool lastButtonState = false;
	// bool buttonPressed = readButton();

	int analogX = analogRead(JOY_X);
	int analogY = analogRead(JOY_Y);

	if (analogX < MIN_VAL) snake.setDirection(LEFT);
	else if (analogX > MAX_VAL) snake.setDirection(RIGHT); 
	else if (analogY < MIN_VAL) snake.setDirection(UP);
	else if (analogY > MAX_VAL) snake.setDirection(DOWN);

}

void setup() {
	pinMode(JOY_SW, INPUT_PULLUP);

	tft.initR(INITR_144GREENTAB);
	tft.setRotation(1);
	tft.fillScreen(BLACK);
	tft.setTextColor(WHITE);

	snake.init();

}

void loop() {
	static uint32_t lastMove = 0;
	const uint8_t moveDelay = 500;
	
	if (millis() - lastMove > moveDelay ) {
		lastMove = millis();
		
		controlDirection(snake);
		snake.move();

		tft.fillScreen(BLACK);
		drawGrid();
		snake.draw();

	}
}