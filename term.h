#ifndef _TERM_H_
#define _TERM_H_

#define term_char(c, rgb) c | rgb << 8;
#define VGA_MEM_START 0xb8000
#define VGA_HEIGHT 24
#define VGA_WIDTH 80
#define BG 0
#define FG 2

void term_init();
void term_putchar(char);

#endif
