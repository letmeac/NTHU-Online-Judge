#include <stdio.h>

int dishes[501];

int findMax(int start, int end)
{
    int count[501] = {0};
    for(int i = start; i <= end; i++)
        count[dishes[i]]++;

    int maxCount = count[1];
    int maxDish = 1;
    for(int i = 2; i <= 500; i++) {
        if(maxCount < count[i]) {
            maxCount = count[i];
            maxDish = i;
        }
    }
    return maxDish;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int dishNum;
    scanf("%d", &dishNum);

    for(int i = 1; i <= dishNum; i++) {
        scanf("%d", &dishes[i]);
    }

    int query;
    scanf("%d", &query);

    while(query-- > 0) {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", findMax(start, end));
    }

    return 0;
}
