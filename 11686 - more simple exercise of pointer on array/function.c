#include "function.h"

void array_exchanger(int* array_a, int* array_b, int length)
{
    int i;
    for(i = 0; i < length; i++) {
        int temp = array_a[i];
        array_a[i] = array_b[i];
        array_b[i] = temp;
    }
}
