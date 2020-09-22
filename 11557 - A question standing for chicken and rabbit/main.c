#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int heads, legs;
    scanf("%d %d", &heads, &legs);

    int numChicken, numRabbits;

    // numChicken + numRabbits = heads
    // numChicken * 2 + numRabbits * 4 = legs

    numRabbits = legs / 2 - heads;
    numChicken = heads - numRabbits;

    printf("%d %d\n", numChicken, numRabbits);

    return 0;
}
