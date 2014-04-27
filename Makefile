OBJ = boot.o \
      main.o \
      string.o \
      term.o
TARGET = jos.bin
ISO = jos.iso
LFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
CC = i686-elf-gcc 
CFLAGS = -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
AS = i686-elf-as
GRUB = grub-mkrescue
QEMU = qemu-system-i386
QFLAGS = -kernel

default: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $@

.s.o:
	$(AS) $< -o $@

.c.o:
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
