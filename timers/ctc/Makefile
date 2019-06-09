CC = avr-gcc
CFLAGS = -g -Os -mmcu=atmega328p
BUILDDIR = build
SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))
ELFFILE = $(addprefix $(BUILDDIR)/,main.elf)
HEXFILE = $(ELFFILE:.elf=.hex)

main: init $(OBJECTS)
	# Link objects to elffile
	avr-gcc -g -mmcu=atmega328 -o $(ELFFILE) $(OBJECTS)

	# Convert elffile to intel hex file
	avr-objcopy -j .text -j .data -O ihex $(ELFFILE) $(HEXFILE)

init:
	@@mkdir -p $(BUILDDIR)

clean:
	@rm -rf build

flash: main
	avrdude -c stk500v1 -F -P /dev/ttyUSB0 -b 57600 -p m328p -V -u -U flash:w:$(HEXFILE)

$(BUILDDIR)/%.o: %.c
	avr-gcc -g -Os -mmcu=atmega328 -I include -c $< -o $@
