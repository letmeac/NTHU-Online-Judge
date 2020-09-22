#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int first, num, diff;
    int last, sum;

    scanf("%d %d %d", &first, &num, &diff);

    last = first + (num - 1) * diff;
    sum = (first + last) * num / 2;

    printf("%d %d", last, sum);

    return 0;
}
