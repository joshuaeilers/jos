#include "main.h"
#include "io.h"
#include "term.h"
#include <stddef.h>
#include <stdint.h>

/*
struct gdt_entry {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} __attribute__ ((packed));

struct gdt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__ ((packed));

struct gdt_entry gdt[3];
struct gdt_ptr gp;

extern void gdt_flush();
*/

void kernel_main() {
	size_t i;
	size_t j;

	init();

	for (i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
		printf("0");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("1");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("2");
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("3");
	}

	for (i = 0; i < VGA_WIDTH / 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d", j);
		}
	}

	for (i = 0; i < VGA_WIDTH; i++) {
		printf("4");
	}

	printf("hi");
}

void init() {
	term_init();
}
