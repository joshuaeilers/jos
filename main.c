#include "main.h"
#include "io.h"
#include "term.h"

int main() {
	init();

	printf("Hello world!\n", 0);
	printf("Goodbye %s %s %s!\n", "world", "world", "world");

	printf("real printf %d %x\n", 0, 0);
	printf("real printf %d %x\n", 1, 1);
	printf("real printf %d %x\n", 2, 2);
	printf("real printf %d %x\n", 3, 4);
	printf("real printf %d %x\n", 13, 15);
	printf("real printf %d %x\n", 1337, 1337);
	printf("real printf %d %x\n", (uint32_t) 4294967295, (uint32_t) 4294967295);
	printf("real printf %d %x %d\n", 11, 11, 12);
	printf("real printf %d %x\n", 128, 128);
	printf("real printf %d %x\n", 10, 0xA);
	printf("real printf %d %s\n", 10, 0xA);

	return 1;
}

void init() {
	term_init();
}
