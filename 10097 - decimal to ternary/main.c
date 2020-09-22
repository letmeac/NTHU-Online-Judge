#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num, digit;
    scanf("%d %d", &num, &digit);

    int i = 0;
    int arr[10] = {0};

    while(num > 0) {
        arr[i] = num % 3;
        num /= 3;
        i++;
    }

    while(digit-- > 0) {
        printf("%d", arr[digit]);
    }
    printf("\n");

    return 0;
}
