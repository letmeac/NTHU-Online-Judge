#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    unsigned long long num;
    scanf("%llu", &num);

    int i = 0;
    int arr[100] = {0};

    while(num > 0) {
        arr[i] = num % 2;
        num /= 2;
        i++;
    }

    while(i-- > 0) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
