#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int numFiveCoins, numTenCoins, spentCoins;
    scanf("%d %d %d", &numFiveCoins, &numTenCoins, &spentCoins);

    printf("%d\n", 5 * numFiveCoins + 10 * numTenCoins - spentCoins);

    return 0;
}
