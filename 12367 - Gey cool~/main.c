#include <stdio.h>

long long arr[2000001];
long long PrefixSum[2000001];

long long getSum(int start, int end)
{
    if(start == end)
        return arr[start];

    return PrefixSum[end] - PrefixSum[start - 1];
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num, queriesNum;

    while(scanf("%d %d", &num, &queriesNum) != EOF) {

        for(int i = 1; i <= num; i++)
            scanf("%lld", &arr[i]);

        for(int i = 1; i <= num; i++)
            PrefixSum[i] = PrefixSum[i - 1] + arr[i];

        long long maxValue = 0;
        int maxStart, maxEnd;

        for(int i = 0; i < queriesNum; i++) {

            int start, end;
            scanf("%d %d", &start, &end);

            long long value;
            if(start <= end)
                value = getSum(start, end);
            else
                value = getSum(1, end) + getSum(start, num);

            if(value > maxValue) {
                maxValue = value;
                maxStart = start;
                maxEnd = end;
            }
        }

        printf("Max_range: (%d,%d); Value: %lld\n", maxStart, maxEnd, maxValue);

    }

    return 0;
}
