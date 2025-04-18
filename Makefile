run:
	avr-gcc -O2 -mmcu=atmega328p -c -o main.o main.c
	avr-gcc -o main.bin main.o
	avr-objcopy -O ihex -R .eeprom main.bin main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex
clean:
	rm -rf main.o main.bin main.hex