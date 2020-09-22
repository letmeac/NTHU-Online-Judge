#include <stdio.h>
#include "function.h"

#define MAX_FLOOR_NUM 20000

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int floorNum;
    int i;

    Floor floorArr[MAX_FLOOR_NUM];

    scanf("%d", &floorNum);

    for(i = 0; i < floorNum; i++) {
        scanf(" %c %d", &floorArr[i].color, &floorArr[i].size);
    }

    printf("%d", design(floorNum, floorArr));

    return 0;
}
