#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>

int compare(const void* a, const void* b);
void assign(char* x, char* y, size_t size);
void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*));

#endif
