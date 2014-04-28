A_SRC = $(wildcard *.s)
C_SRC = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = $(C_SRC:.c=.o) $(A_SRC:.s=.o)
TARGET = jos.bin
ISO = jos.iso
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
CC = i686-elf-gcc 
CFLAGS = -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
AS = i686-elf-as
GRUB = grub-mkrescue
QEMU = qemu-system-i386
QFLAGS = -kernel

.PHONY: all iso run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.s
	$(AS) $< -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

iso:
	mkdir -p isodir
	mkdir -p isodir/boot
	cp $(TARGET) isodir/boot/$(TARGET)
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	$(GRUB) -o $(ISO) isodir

run:
	$(QEMU) $(QFLAGS) $(TARGET)

clean:
	rm $(OBJ) $(TARGET) $(ISO)
