#include "term.h"

size_t term_row;
size_t term_col;
uint8_t term_rgb;
uint16_t *term_buf;

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
