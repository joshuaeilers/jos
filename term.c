#include <stddef.h>
#include <stdint.h>
#include "term.h"
#include "lib.h"

size_t term_row;
size_t term_col;
uint8_t term_rgb;
uint16_t *term_buf;

void term_init() {
	size_t i;

	term_row = 0;
	term_col = 0;
	term_rgb = term_rgb(FG, BG);
	term_buf = (uint16_t *) VGA_MEM_START;

	for (i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		term_buf[i] = term_char(' ', term_rgb);
	}
}

void term_putchar(char c) {
	if (c == '\n') {
		term_col = 0;
		term_row++;
	} else if (c >= ' ') {
		term_buf[term_row * VGA_WIDTH + term_col] = term_char(c, term_rgb);

		// if the next char to print will hit the wall
		if (++term_col >= VGA_WIDTH) {
			term_col = 0;
			term_row++;
		}
	}

	if (term_row > VGA_HEIGHT) {
		memcpy(term_buf, term_buf + VGA_WIDTH, VGA_HEIGHT * VGA_WIDTH * 2);
		memsetw(term_buf + (VGA_HEIGHT * VGA_WIDTH), term_char(' ', term_rgb), VGA_WIDTH);
		term_row = VGA_HEIGHT;
	}
}
