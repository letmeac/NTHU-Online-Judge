#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int length, width;
    scanf("%d %d", &length, &width);

    int** int_2D_array = (int**)malloc(length * sizeof(int*));
    for(int i = 0; i < length; i++) {
        int_2D_array[i] = (int*)malloc(width * sizeof(int));
    }

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            scanf("%d", &int_2D_array[i][j]);
        }
    }

    printf("%d\n", get_sum(int_2D_array, length, width));
}
