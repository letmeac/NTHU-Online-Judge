#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    MyData data[100];
    MyData* book[100];
    int i, size;

    scanf("%d", &size);

    for(i = 0; i < size; i++) {
        scanf("%d", &data[i].value);
    }
    for(i = 0; i < size; i++) {
        scanf("%s", data[i].str);
    }
    for(i = 0; i < size; i++) {
        scanf("%f", &data[i].x);
    }

    for(i = 0; i < size; i++) {
        book[i] = &data[i];
    }

    qsort(book, size, sizeof(MyData*), compare_function);

    for(i = size - 1; i >= 0; i--) {
        printf("%d %s %.3f\n", book[i]->value, book[i]->str, book[i]->x);
    }

    return 0;
}
