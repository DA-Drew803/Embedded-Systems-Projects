MCU ?= atmega328p
F_CPU ?= 16000000UL
CC := avr-gcc
OBJCOPY := avr-objcopy
CFLAGS := -std=c11 -Os -Wall -Wextra -Wpedantic -mmcu=$(MCU) -DF_CPU=$(F_CPU)

LAB ?= lab01-morse-led
SOURCE := $(LAB)/main.c
BUILD_DIR := build/$(LAB)
ELF := $(BUILD_DIR)/firmware.elf
HEX := $(BUILD_DIR)/firmware.hex

.PHONY: all clean

all: $(HEX)

$(ELF): $(SOURCE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -rf build

