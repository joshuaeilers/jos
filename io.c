#include "io.h"
#include "lib.h"
#include "str.h"
#include "term.h"
#include <stdarg.h>

void putchar(char c) {
	term_putchar(c);
}

void puts(const char *s) {
	while (*s) {
		putchar(*s);
		++s;
	}
}

void printf(const char *s, ...) {
	char buf[MAX_UINT32_LENGTH + 1];
	va_list arg_list;

	va_start(arg_list, s);

	while (*s) {
		if (*s == '%') {
			++s;

			if (*s == 'd') {
				puts(itoa(buf, va_arg(arg_list, uint32_t), 10));
			} else if (*s == 'x') {
				puts(itoa(buf, va_arg(arg_list, uint32_t), 16));
			} else if (*s == 's') {
				puts(va_arg(arg_list, const char *));
			} else {
				puts("Invalid printf format!\n");
				break;
			}
		} else {
			putchar(*s);
		}

		++s;
	}

	va_end(arg_list);
}