#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    double c;
    scanf("%lf", &c);
    printf("%lf\n", c * 9 / 5 + 32);

    return 0;
}
