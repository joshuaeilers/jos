#include "io.h"
#include "lib.h"
#include "str.h"
#include "term.h"
#include <stdarg.h>

void putchar(char c) {
	term_putchar(c);
}

void puts(const char *s) {
	size_t i;
	size_t len = strlen(s);

	for (i = 0; i < len; i++) {
		putchar(s[i]);
	}
}

void printf(const char *s, ...) {
	size_t i;
	size_t len = strlen(s);
	char buf[12];
	va_list arg_list;

	va_start(arg_list, s);

	for (i = 0; i < len; i++) {
		if (s[i] == '%') {
			++i;
			if (s[i] == 'd') {
				itoa(buf, va_arg(arg_list, uint32_t));
				puts(buf);
			} else if (s[i] == 'x') {
				itoh(buf, va_arg(arg_list, uint32_t));
				puts(buf);
			} else if (s[i] == 's') {
				puts(va_arg(arg_list, const char *));
			} else {
				puts("Invalid printf format!\n");
				break;
			}
		} else {
			putchar(s[i]);
		}
	}

	va_end(arg_list);
}
