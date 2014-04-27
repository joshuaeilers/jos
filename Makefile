EXE=myos.bin
ISO=myos.iso
CC=i686-elf-gcc 
CFLAGS=-c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
AS=i686-elf-as

default: $(EXE)

$(EXE): boot.o main.o
	$(CC) -T linker.ld -o $(EXE) -ffreestanding -O2 -nostdlib boot.o main.o -lgcc

boot.o: boot.s
	$(AS) boot.s -o boot.o

main.o: main.c main.h string.h term.h
	$(CC) $(CFLAGS) main.c -o main.o 

term.o: term.c term.h
	$(CC) $(CFLAGS) term.c -o term.o 

string.o: string.c string.h term.h
	$(CC) $(CFLAGS) string.c -o string.o

clean:
	rm *.o $(EXE) $(ISO)
