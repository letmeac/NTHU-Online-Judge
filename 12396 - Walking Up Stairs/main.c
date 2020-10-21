#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int stairNum;
    scanf("%d", &stairNum);

    unsigned long long stairWay[117];
    stairWay[0] = stairWay[1] = stairWay[2] = 1;

    for(int i = 3; i <= stairNum; i++)
        stairWay[i] = stairWay[i - 1] + stairWay[i - 3];

    printf("%llu\n", stairWay[stairNum]);

    return 0;
}
