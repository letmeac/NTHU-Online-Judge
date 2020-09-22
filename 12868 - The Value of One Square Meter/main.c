#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int width, length, price;
    scanf("%d %d %d", &width, &length, &price);

    printf("$%.2fNTD\\m2\n", (float)price / (width * length));

    return 0;
}
