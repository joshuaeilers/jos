#include "str.h"

size_t strlen(const char *s) {
	register const char *r;

	for (r = s; *r; r++);

	return (r - s);
}
