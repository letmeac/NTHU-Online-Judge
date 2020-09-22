#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int AB, BC, AC;
    scanf("%d %d %d", &AB, &BC, &AC);

    int sum = (AB + BC + AC) / 2;
    int A = sum - BC;
    int B = sum - AC;
    int C = sum - AB;

    printf("%d %d %d\n", A, B, C);

    return 0;
}
