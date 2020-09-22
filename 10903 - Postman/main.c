#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;

    // Read inputs
    scanf("%d", &n);
    Letter *letters = malloc(sizeof(Letter) * n);

    int i;
    for(i = 0; i < n; i++)
        scanf("%d %s", &letters[i].zipcode, letters[i].name);

    // Sort the data
    qsort(letters, n, sizeof(Letter), compare);

    // Output result
    for(i = 0; i < n; i++)
        printf("%d %s\n", letters[i].zipcode, letters[i].name);

    free(letters);

    return 0;
}
