#include "lib.h"

char *itoa(char *buf, uint32_t x, uint16_t base) {
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

	return (buf + i);
}

void memcpy(void *dest, const void *src, size_t n) {
	const uint32_t *s = src;
	uint32_t *d = dest;
	const uint8_t *s1;
	uint8_t *d1;

	// how many 4 byte chunks can we do first
	while (n >= 4) {
		*d++ = *s++;
		n -= 4;
	}

	// copy remaining single bytes
	s1 = (uint8_t *) s;
	d1 = (uint8_t *) d;

	while (n-- > 0) {
		*d1++ = *s1++;
	}
}

void memsetw(void *dest, uint16_t v, size_t n) {
	uint16_t *d;

	for (d = dest; n > 0; --n, ++d) {
		*d = v;
	}
}

void memset(void *dest, uint8_t v, size_t n) {
	uint8_t *d;

	for (d = dest; n > 0; --n, ++d) {
		*d = v;
	}
}
