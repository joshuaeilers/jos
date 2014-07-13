#include "term.h"
#include "lib.h"
#include <stddef.h>

#define term_char(c, rgb) c | rgb << 8
#define term_rgb(fg, bg) fg | bg << 4
#define is_print(c) (c >= 0x20 && c <= 0x7e)
#define VGA_MEM_START 0xb8000
#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define BG 0
#define FG 2

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

void term_putchar(uint8_t c) {
	if (c == '\n') {
		term_col = 0;
		term_row++;
	} else if (is_print(c)) {
		term_buf[term_row * VGA_WIDTH + term_col] = term_char(c, term_rgb);

		if (++term_col >= VGA_WIDTH) {
			term_col = 0;
			term_row++;
		}
	}

	if (term_row >= VGA_HEIGHT) {
		memcpy(term_buf, term_buf + VGA_WIDTH, (VGA_HEIGHT - 1) * VGA_WIDTH * sizeof(uint16_t));
		memsetw(term_buf + (VGA_HEIGHT - 1) * VGA_WIDTH, term_char(' ', term_rgb), VGA_WIDTH);
		term_row = VGA_HEIGHT - 1;
	}
}
