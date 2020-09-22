#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    return 0;
}
