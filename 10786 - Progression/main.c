#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int second, third, fourth;
    scanf("%d %d %d", &second, &third, &fourth);

    if(third - second == fourth - third) {
        int diff = third - second;
        printf("%d %d", second - diff, fourth + diff);
    }
    else {
        int times = third / second;
        printf("%d %d", second / times, fourth * times);
    }

    return 0;
}
