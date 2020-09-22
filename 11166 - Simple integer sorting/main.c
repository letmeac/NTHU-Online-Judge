#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int num;
        scanf("%d", &num);

        int i;
        int arr[10000];

        for(i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, num, sizeof(int), compare);

        for(i = 0; i < num; i++) {
            printf("%d", arr[i]);
            if(i < num - 1) printf(" ");
        }

        printf("\n");
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}
