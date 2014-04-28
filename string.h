#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>
#include <stdint.h>

size_t itoa(char *, uint32_t);
size_t itoh(char *, uint32_t);
size_t strlen(const char *);
void putchar(char);
void puts(const char *);
void printf(const char *, uint32_t);

#endif
