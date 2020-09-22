#include <string.h>
#include "function.h"

int compare_function(const void* a, const void* b)
{
    MyData *data_a = *(MyData**)a;
    MyData *data_b = *(MyData**)b;

    if(data_a->value < data_b->value) return -1;
    else if(data_a->value > data_b->value) return 1;
    else if(strcmp(data_a->str, data_b->str) < 0) return -1;
    else if(strcmp(data_a->str, data_b->str) > 0) return 1;
    else if(data_a->x < data_b->x) return -1;
    else if(data_a->x > data_b->x) return 1;

    return 0;
}
