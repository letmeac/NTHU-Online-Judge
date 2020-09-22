#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct
{
    int value;
    char str[30];
    float x;
} MyData;

int compare_function(const void* a, const void* b);

#endif
