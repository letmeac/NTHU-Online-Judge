#include <stdio.h>
#include <limits.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int max = 0;
    int min = INT_MAX;

    int num;
    while(1) {
        scanf("%d", &num);
        if(num == -1) break;

        max = (num > max) ? num : max;
        min = (num < min) ? num : min;
    }

    printf("%d %d\n", max, min);

    return 0;
}
