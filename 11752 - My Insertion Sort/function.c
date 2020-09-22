#include "function.h"

int compare(const void* a, const void* b)
{
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

void assign(char* x, char* y, size_t size)
{
    while(size > 0) {
        char temp = *x;
        *x = *y;
        *y = temp;

        x++;
        y++;
        size--;
    }
}

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*))
{
    char* a = (char*)arr;
    int i, j;

    i = 1;
    while(i < count) {
        j = i;
        while(j > 0 && cmp(a+(j-1)*size, a+j*size) > 0) {
            assign(a+(j-1)*size, a+j*size, size);
            j--;
        }
        i++;
    }
}
