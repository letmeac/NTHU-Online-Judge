#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b;
    int sum;

    scanf("%x %x", &a, &b);
    sum = a + b;

    int i = 0;
    int arr[100] = {0};

    while(sum > 0) {
        arr[i] = sum % 2;
        sum /= 2;
        i++;
    }

    while(i-- > 0) {
        printf("%d", arr[i]);
    }

    return 0;
}
