#include "lib.h"

size_t itoa(char *buf, uint32_t x, uint16_t base) {
	char *digits = "0123456789ABCDEF";
	size_t i = MAX_UINT32_LENGTH;
	uint32_t n;

	buf[i] = '\0';

	// only handling positive integers for now
	do {
		n = x % base;
		buf[--i] = digits[n];
		x /= base;
	} while (x > 0);

	if (base == 16) {
		buf[--i] = 'x';
		buf[--i] = '0';
	}

	return &buf[i];
}
