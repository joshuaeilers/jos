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

	return &buf[i];
}

void *memcpy(void *dest, const void *src, size_t n) {
	const uint8_t *s = src;
	uint8_t *d = dest;
	uint32_t *s4 = (uint32_t *) src;
	uint32_t *d4 = dest;

	// how many 4 byte chunks can we do first
	size_t n4 = n / sizeof(uint32_t);
	size_t nr = n % sizeof(uint32_t);

	while (n4--) {
		*d4++ = *s4++;
	}

	// are there any bytes left?
	if (nr > 0) {
		d = (uint8_t *) d4;
		s = (const uint8_t *) s4;

		while (nr--) {
			*d++ = *s++;
		}
	}

	return dest;
}

void *memsetw(void *dest, uint16_t v, size_t n) {
	uint16_t *d = dest;

	while (n--) {
		*d++ = v;
	}

	return dest;
}
