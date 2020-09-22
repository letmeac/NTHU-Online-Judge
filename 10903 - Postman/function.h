#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct
{
    int zipcode;
    char name[15];
} Letter;

int compare(const void *a, const void *b);

#endif
