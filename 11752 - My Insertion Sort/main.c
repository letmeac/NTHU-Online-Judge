#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int* data;
    int i;
    int size = 0;

    scanf("%d", &size);
    data = malloc(size * sizeof(int));

    for(i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    mysort(data, size, sizeof(int), compare);

    for(i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);

    return 0;
}
