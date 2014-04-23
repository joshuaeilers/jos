#ifndef _TERM_H_
#define _TERM_H_

#include <stddef.h>
#include <stdint.h>

#define VGA_HEIGHT 24
#define VGA_WIDTH 80
#define BG 0
#define FG 2

extern size_t term_row;
extern size_t term_col;
extern uint8_t term_rgb;
extern uint16_t *term_buf;

void term_init();

#endif
