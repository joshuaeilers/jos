#include "lib.h"

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
