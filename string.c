#include "string.h"
#include "term.h"

size_t strlen(const char *s) {
	size_t i = 0;

	while (s[i]) {
		i++;
	}

	return i;
}

size_t itoa(char *buf, uint32_t x) {
	size_t i = 0;
	size_t j = 0;
	char n;
	char tmp[11]; // 4294967295\0 (11 digits) is longest uint32_t

	// only handling positive integers for now

	do {
		n = x % 10;
		tmp[i++] = n + '0';
	} while (x /= 10);

	while (i) {
		buf[j++] = tmp[--i];
	}

	buf[j] = '\0';

	return j;
}

size_t itoh(char *buf, uint32_t x) {
	char *hex = "0123456789ABCDEF";
	char tmp[11]; // 0xFFFFFFFF\0 (11 digits) is longest uint32_t
	size_t i = 0;
	size_t j = 0;
	size_t n;

	// only handling positive integers for now

	buf[j++] = '0';
	buf[j++] = 'x';

	do {
		n = x % 16;
		tmp[i] = hex[n];
		i++;
	} while (x /= 16);

	while (i) {
		buf[j++] = tmp[--i];
	}

	buf[j] = '\0';

	return j - 2;
}

void putchar(char c) {
	term_entry(c); // normally would place c at stdout
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
