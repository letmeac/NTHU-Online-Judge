#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    printf("%d", X + Y - Z);

    return 0;
}
