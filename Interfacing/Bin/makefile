#File name: makefile
#Purpose:   Contains the compiler commands to have the final executable image (.hex)
#Author:    Ahmed Ashraf
#Date:      9-9-2022
#Version:   v1.0

all: main.c clean main.hex

main.elf:
	avr-gcc -mmcu=atmega32 -DF_CPU=16000000 -Wall -Os -c main.c
	avr-gcc -Wl,-Map=main.map -mmcu=atmega32 main.o -o main.elf

main.hex: main.elf
	avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature main.elf -O ihex main.hex

clean:
	rm -rf *.hex *.elf *.map *.o