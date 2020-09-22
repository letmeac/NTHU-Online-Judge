#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct
{
    char color;
    unsigned int size;
} Floor;

int compare(const void *a, const void *b);
int design(int floorNum, Floor floorArr[]);

#endif
