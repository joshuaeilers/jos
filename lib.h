#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stddef.h>
#include <stdint.h>

#define MAX_UINT32_LENGTH 10

char *itoa(char *, uint32_t, uint16_t);
void memcpy(void *, const void *, size_t);
void memsetw(void *, uint16_t, size_t);

#endif
