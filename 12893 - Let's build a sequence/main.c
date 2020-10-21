#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n, a1, a2, a3;
    scanf("%d %d %d %d", &n, &a1, &a2, &a3);

    int b1 = a2 - a1;
    int b2 = a3 - a2;

    int diff = b2 - b1;

    printf("%d %d %d", a1, a2, a3);
    int preA = a3;
    int preB = b2;
    for(int i = 1; i <= n - 3; i++) {
        preB += diff;
        preA = preA + preB;
        printf(" %d", preA);
    }
    printf("\n");

    return 0;
}
