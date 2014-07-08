#include "io.h"
#include "lib.h"
#include "str.h"
#include "term.h"

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

void printf(const char *s, uint32_t x) {
	size_t i;
	size_t len = strlen(s);
	char buf[11];

	for (i = 0; i < len; i++) {
		if (s[i] == '%') {
			++i;
			if (s[i] == 'd') {
				itoa(buf, x);
				puts(buf);
			} else if (s[i] == 'x') {
				itoh(buf, x);
				puts(buf);
			}
		} else {
			putchar(s[i]);
		}
	}
}
