#include <stdlib.h>
#include "function.h"

int get_sum(int** int_2D_array, int length, int width)
{
    int i, j;
    int sum = 0;

    for(i = 0; i < length; i++) {
        for(j = 0; j < width; j++) {
            sum += int_2D_array[i][j];
        }
    }

    for(i = 0; i < length; i++)
        free(int_2D_array[i]);
    free(int_2D_array);

    return sum;
}
