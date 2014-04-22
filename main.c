#include "main.h"

#define VGA_HEIGHT 24
#define VGA_WIDTH 80
#define BG 0
#define FG 2

size_t term_row;
size_t term_col;
uint8_t term_rgb;
uint16_t *term_buf;

void main() {
	term_init();
	puts("Hello world!\n");
	puts("Goodbye world!\n");
}

void term_init() {
	size_t x;
	size_t y;

	term_row = 0;
	term_col = 0;
	term_rgb = BG << 4 | FG;
	term_buf = (uint16_t *) 0xB8000;

	for (y = 0; y < VGA_HEIGHT; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			term_buf[y * VGA_WIDTH + x] = term_rgb << 8 | ' ';
		}
	}
}

void putchar(char c) {
	if (c == '\n') {
		term_row++;
		term_col = 0;
		return;
	}

	term_buf[term_row * VGA_WIDTH + term_col] = term_rgb << 8 | c;

	if (++term_col == VGA_WIDTH) {
		term_col = 0;

		if (++term_row == VGA_HEIGHT) {
			term_row = 0;
		}
	}
}

void puts(const char *s) {
	size_t i;
	size_t len = strlen(s);

	for (i = 0; i < len; i++) {
		putchar(s[i]);
	}
}

size_t strlen(const char *s) {
	size_t i = 0;

	while (s[i]) {
		i++;
	}

	return i;
}
