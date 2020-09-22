#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    int i, j;
    int number[100000];

    for(i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    int minBitNum[20];

    // binary digit number of 1000000(maximun number) is 20
    for(i = 0; i < 20; i++) {

        // record number of 0s and 1s on this digit for all numbers
        int Num[2] = {0};
        for(j = 0; j < n; j++) {
            Num[number[j] & 1]++;
            number[j] >>= 1;
        }

        // record the minimun number of 0s or 1s
        minBitNum[i] = min(Num[0], Num[1]);
    }

    long long SUM = 0;
    for(i = 19; i > 0; i--) {
        SUM += minBitNum[i];
        SUM <<= 1;
    }
    SUM += minBitNum[0];

    printf("%lld\n", SUM);

    return 0;
}
