#ifndef ZERO_STRING_H
#define ZERO_STRING_H

#include "stdlib.h"

#define STR_END '\0'

/**
 *
 * 实现c语言string基本的函数。
 * 主要用学习对char*使用。
 */


int strlen(const char *str);

int strcmp(const char *p, const char *q);

char *strdup(const char *src);

char *strchr(const char *src, char c);

char *strcpy(char *dst, const char *src);

char *strcat(char *dst, const char *src);

char *strstr(const char *str1, const char *str2);

long strtol(const char *str, char **endptr, int base);


void *memset(void *dst, int val, size_t count);

void *memmove(void *dst, const void *src, size_t n);

int memcmp(const void *p, const void *q, size_t n);

#endif //ZERO_STRING_H
