CC=avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Wall
CCFLAGS=-Os -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

%elf: %o
	$(CC) -o $@ $< libcore.a

%.hex: %.elf
	avr-objcopy -O ihex $< $@

%.lst: %.elf
	avr-objdump -d $< > $@

%.s: %.c
	$(CC) $(CCFLAGS) -c -S $<

TARGETS = $(patsubst %.c,%.hex,$(wildcard *.c))

# Uncomment below to keep intermediate
# .SECONDARY:

all: $(TARGETS)

upload: ${program}.hex
	avrdude -D -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:$<

com:
	picocom /dev/ttyACM0

clean:
	rm -f $(TARGETS) *.o *.elf *.s
