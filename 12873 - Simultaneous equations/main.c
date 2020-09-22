#include <stdio.h>

int deter(int a, int b, int c, int d)
{
    return a * d - b * c;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int delta = deter(a, b, d, e);
    int delta_x = deter(c, b, f, e);
    int delta_y = deter(a, c, d, f);

    printf("%d %d", delta_x / delta, delta_y / delta);

    return 0;
}
