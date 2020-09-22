#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int seatNum;
        scanf("%d", &seatNum);

        printf("%d\n", seatNum / 2 + 1);
    }

    return 0;
}
