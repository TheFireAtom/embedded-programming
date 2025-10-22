# Configuration variables
MCU = atmega328p          # Change for other chips, e.g., atmega2560 for Mega
PORT = COM3               # Your serial port (e.g., COM3 on Windows, /dev/ttyUSB0 on Linux/macOS)
BAUD = 115200             # Bootloader baud rate (115200 for Uno)
CFLAGS = -mmcu=$(MCU) -Os -Wall  # Compiler flags: target MCU, optimize for size, warnings

# Main commands:

# Default target: build the hex file
all: main.hex

# Compile C to ELF
main.elf: main.cpp
	avr-gcc $(CFLAGS) -o main.elf main.cpp

# Convert ELF to Intel HEX
main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

# Upload to board
upload: main.hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:main.hex:i

# Clean up build files
clean:
	rm -f main.elf main.hex

# Phony targets (not actual files)
.PHONY: all upload clean

# Sleep mode:

# Build and upload sleep/off code
off.elf: off.cpp
	avr-gcc $(CFLAGS) -o off.elf off.cpp

off.hex: off.elf
	avr-objcopy -O ihex off.elf off.hex

off: off.hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:off.hex:i

# Update clean to include off files
clean:
	rm -f main.elf main.hex off.elf off.hex

# Reset the board
reset:
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -v