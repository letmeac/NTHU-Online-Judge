#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b, c;
    scanf("%1d%1d%1d", &a, &b, &c);

    int abc = 100 * a + 10 * b + c;
    int cba = 100 * c + 10 * b + a;

    float avg = (abc + cba) * 0.5;
    printf("%.1f", avg);

    return 0;
}
