#include <stdio.h>
#include <limits.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int Row, Col;
    scanf("%d %d", &Row, &Col);

    int i, j;
    int ColSum[10] = {0};

    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            int num;
            scanf("%d", &num);
            ColSum[j] += num;
        }
    }

    int MaxColSum = INT_MIN;

    for(i = 0; i < Col; i++) {
        if(ColSum[i] > MaxColSum)
            MaxColSum = ColSum[i];
    }

    printf("%d", MaxColSum);

    return 0;
}
