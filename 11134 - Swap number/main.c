#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int arr[5];
    for(int i = 0; i < 5; i++)
        arr[i] = i;

    int k;
    scanf("%d", &k);

    while(k-- > 0) {
        int i, j;
        scanf("%d %d", &i, &j);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    printf("%d", arr[0]);
    for(int i = 1; i < 5; i++)
        printf(" %d", arr[i]);

    return 0;
}
