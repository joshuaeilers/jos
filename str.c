#include "str.h"

size_t strlen(const char *s) {
	const char *r;

	for (r = s; *r; r++);

	return (r - s);
}
