#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    num = (num % 100) * 100 + num / 100;
    num = num * num;

    char itol[10] = {'J', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

    int digit = 8;
    int divisor = (int)1E7;
    while(digit-- > 0) {
        printf("%c", itol[num/divisor]);
        num %= divisor;
        divisor /= 10;
    }
    printf("\n");

    return 0;
}
