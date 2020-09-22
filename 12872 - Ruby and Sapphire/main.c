#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a1_b1, a5_b7;
    scanf("%d %d", &a1_b1, &a5_b7);

    int b = (a5_b7 - a1_b1 * 5) / 2;
    int a = a1_b1 - b;

    printf("%d %d\n", a, b);

    return 0;
}
