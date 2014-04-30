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
	term_buf = (uint16_t *) 0xB8000;

	for (i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
		term_buf[i] = ' ' | term_rgb << 8;
	}
}

void term_entry(char c) {
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

	term_buf[term_row * VGA_WIDTH + term_col] = c | term_rgb << 8;

	if (++term_col == VGA_WIDTH) {
		term_col = 0;

		if (++term_row == VGA_HEIGHT) {
			term_row = 0;
		}
	}
}
