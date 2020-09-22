#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    int i;
    int nowSum = 0;
    int partitionNum = 0;

    for(i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);
        if(nowSum + number > 10) {
            nowSum = 0;
            partitionNum++;
        }
        nowSum += number;
    }
    partitionNum++;

    printf("%d", partitionNum);

    return 0;
}
