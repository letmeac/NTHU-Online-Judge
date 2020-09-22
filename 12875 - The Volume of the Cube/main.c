#include <stdio.h>
#include <math.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    double w, l, h;
    scanf("%lf %lf %lf", &w, &l, &h);

    printf("%d m3\n", (int)round(w * l * h));

    return 0;
}
