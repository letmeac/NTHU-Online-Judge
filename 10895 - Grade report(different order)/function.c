#include <stdlib.h>
#include <string.h>
#include "function.h"

#define ascending "ascending"
#define descending "descending"

int cmpAscend(const void *a, const void *b);
int cmpDescend(const void *a, const void *b);

void sortGrade(Grade *gList, int n, char *order)
{
    int i;
    for(i = 0; i < n; i++) {
        gList[i].total = gList[i].Chinese + 
                         gList[i].English + 
                         gList[i].math + 
                         gList[i].science;
    }

    if(strcmp(order, ascending) == 0) {
        qsort(gList, n, sizeof(Grade), cmpAscend);
    }
    else if(strcmp(order, descending) == 0) {
        qsort(gList, n, sizeof(Grade), cmpDescend);
    }
}

int cmpAscend(const void *a, const void *b)
{
    Grade *grade_a = (Grade*)a;
    Grade *grade_b = (Grade*)b;

    if(grade_a->total < grade_b->total) return -1;
    else if(grade_a->total > grade_b->total) return 1;
    else if(grade_a->Chinese < grade_b->Chinese) return -1;
    else if(grade_a->Chinese > grade_b->Chinese) return 1;
    else if(grade_a->English < grade_b->English) return -1;
    else if(grade_a->English > grade_b->English) return 1;
    else if(grade_a->math < grade_b->math) return -1;
    else if(grade_a->math > grade_b->math) return 1;
    else if(grade_a->science < grade_b->science) return -1;
    else if(grade_a->science > grade_b->science) return 1;
    else if(grade_a->ID < grade_b->ID) return -1;
    else if(grade_a->ID > grade_b->ID) return 1;

    return 0;
}

int cmpDescend(const void *a, const void *b)
{
    Grade *grade_a = (Grade*)a;
    Grade *grade_b = (Grade*)b;

    if(grade_a->total > grade_b->total) return -1;
    else if(grade_a->total < grade_b->total) return 1;
    else if(grade_a->Chinese > grade_b->Chinese) return -1;
    else if(grade_a->Chinese < grade_b->Chinese) return 1;
    else if(grade_a->English > grade_b->English) return -1;
    else if(grade_a->English < grade_b->English) return 1;
    else if(grade_a->math > grade_b->math) return -1;
    else if(grade_a->math < grade_b->math) return 1;
    else if(grade_a->science > grade_b->science) return -1;
    else if(grade_a->science < grade_b->science) return 1;
    else if(grade_a->ID < grade_b->ID) return -1;
    else if(grade_a->ID > grade_b->ID) return 1;

    return 0;
}
