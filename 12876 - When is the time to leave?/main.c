#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int H, M, T;
    scanf("%d %d %d", &H, &M, &T);

    H = (H + (M + T) / 60) % 24;
    M = (M + T) % 60;

    printf("%d:%d\n", H, M);

    return 0;
}
