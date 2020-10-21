#include <stdio.h>

const int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int M, D;
    scanf("%d/%d", &M, &D);

    int i;
    int totalDay = D;
    for(i = 1; i < M; i++)
        totalDay += month[i];

    printf("%d\n", totalDay);

    return 0;
}
