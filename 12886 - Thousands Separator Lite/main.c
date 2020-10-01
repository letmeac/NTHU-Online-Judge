#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num3, num2, num1;
    int sum = 0;

    int i;
    for(i = 0; i < 2; i++) {
        scanf("%d,%d,%d", &num3, &num2, &num1);
        sum += num3 * 1000000 + num2 * 1000 + num1;
    }
    printf("%d\n", sum);

    return 0;
}
