#include "main.h"
#include "gdt.h"
#include "idt.h"
#include "io.h"
#include "term.h"
#include <stddef.h>

void kernel_main() {
	printf("kernel starting");
	init();
}

void init() {
	gdt_install();
	idt_install();
	term_init();
}
