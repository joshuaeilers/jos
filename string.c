#include "string.h"
#include "term.h"

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
