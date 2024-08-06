MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
PROGRAMMER = -c usbasp -p $(MCU)

all: main.hex

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

main.elf: main.o
	$(CC) $(CFLAGS) -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

upload: main.hex
	$(AVRDUDE) $(PROGRAMMER) -U flash:w:$<:i

clean:
	rm -f main.o main.elf main.hex