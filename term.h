#ifndef _TERM_H_
#define _TERM_H_

#include <stdint.h>

#define term_char(c, rgb) c | rgb << 8
#define term_rgb(fg, bg) fg | bg << 4
#define VGA_MEM_START 0xb8000
#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define BG 0
#define FG 2

void term_init();
void term_putchar(uint8_t);

#endif
