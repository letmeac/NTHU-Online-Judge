#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct
{
    int ID;
    int Chinese, English, math, science;
    int total;
} Grade;

void sortGrade(Grade *gList, int n, char *order);

#endif
