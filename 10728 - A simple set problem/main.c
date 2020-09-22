#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int N, X, Y, Z;
    scanf("%d %d %d %d", &N, &X, &Y, &Z);

    printf("%d %d", X+Y-N+Z, N-Z-Y);

    return 0;
}
