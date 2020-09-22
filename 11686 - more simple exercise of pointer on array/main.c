#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int length = 0;
    scanf("%d", &length);

    int *array_a, *array_b;

    array_a = (int*)malloc(length * sizeof(int));
    array_b = (int*)malloc(length * sizeof(int));

    for(int i = 0; i < length; i++) {
        scanf("%d", &array_a[i]);
    }

    for(int i = 0; i < length; i++) {
        scanf("%d", &array_b[i]);
    }

    array_exchanger(array_a, array_b, length);

    printf("%d", array_a[0]);
    for(int i = 1; i < length; i++) {
        printf(" %d", array_a[i]);
    }
    printf("\n");

    printf("%d", array_b[0]);
    for(int i = 1; i < length; i++) {
        printf(" %d", array_b[i]);
    }

    free(array_a);
    free(array_b);
}
