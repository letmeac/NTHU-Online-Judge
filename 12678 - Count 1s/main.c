#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int getNumOfOnes(int num) {
    int i;
    int res = 0;
    for(i = 1; i <= num; i *= 10) {
        int divider = i * 10;
        res += (num / divider) * i + min(max(num % divider - i + 1, 0), i);
    }
    return res;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", getNumOfOnes(b) - getNumOfOnes(a - 1));
    }

    return 0;
}
