#include <stddef.h>
#include <stdint.h>
#include "term.h"

size_t term_row;
size_t term_col;
uint8_t term_rgb;
uint16_t *term_buf;

void term_init() {
	size_t i;

	term_row = 0;
	term_col = 0;
	term_rgb = FG | BG << 4;
	term_buf = (uint16_t *) VGA_MEM_START;

	for (i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		term_buf[i] = term_char(' ', term_rgb);
	}
}

void term_putchar(char c) {
	if (c == '\n') {
		/*
		 * Check if end of screen is reached
		 */
		term_row++;
		term_col = 0;
		return;
	}

	/*
	 * Check if end of screen is reached
	 */

	term_buf[term_row * VGA_WIDTH + term_col] = term_char(c, term_rgb);

	if (++term_col == VGA_WIDTH) {
		term_col = 0;

		if (++term_row == VGA_HEIGHT) {
			term_row = 0;
		}
	}
}
