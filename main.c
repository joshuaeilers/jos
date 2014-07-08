#include "main.h"
#include "io.h"
#include "term.h"

int main() {
	init();

	printf("Hello world!\n", 0);
	printf("Goodbye world!\n", 0);
	printf("printf worked %d !\n", 0);
	printf("printf worked %d !\n", 3);
	printf("printf worked %d !\n", 4422);
	printf("printf worked %d !\n", 9000);
	printf("printf worked %d !\n", 1337);
	printf("printf worked %d !\n", 4294967295);
	printf("printf worked %d !\n", 11);

	printf("printf worked %x !\n", 0);
	printf("printf worked %x !\n", 3);
	printf("printf worked %x !\n", 4422);
	printf("printf worked %x !\n", 9000);
	printf("printf worked %x !\n", 1337);
	printf("printf worked %x !\n", 4294967295);
	printf("printf worked %x !\n", 17);

	return 1;
}

void init() {
	term_init();
}
