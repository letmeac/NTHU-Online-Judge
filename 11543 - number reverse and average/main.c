#include <stdio.h>

int reverse(int num)
{
    int ret = 0;
    while(num) {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return ret;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    printf("%.1f", 0.5 * ((float)num + (float)reverse(num)));

    return 0;
}
