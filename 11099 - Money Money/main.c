#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int X, Y, Z;
    int Jay, Jolin, JJ;

    scanf("%d %d %d", &X, &Y, &Z);

    int sum = (X + Y + Z) / 2;
    Jay = sum - Y;
    Jolin = sum - Z;
    JJ = sum - X;

    printf("%d %d %d\n", Jay, Jolin, JJ);

    return 0;
}
