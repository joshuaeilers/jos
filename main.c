#include "main.h"
#include "io.h"
#include "term.h"

int main() {
	int i;
	int j;

	init();

	// issue is when we try to print to the last screen position (80)
	for (i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
		printf("0");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("1");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("2");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("3");
	}

	for (i = 0; i < VGA_WIDTH / 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d", j);
		}
	}

	return 1;
}

void init() {
	term_init();
}
