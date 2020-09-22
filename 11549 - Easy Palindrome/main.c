#include <stdio.h>

int reverse(int num) {
    int newNum = 0;
    while(num) {
        newNum = newNum * 10 + num % 10;
        num /= 10;
    }
    return newNum;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    double num;
    scanf("%lf", &num);

    int intPart = (int)num;
    double decPart = num - intPart;

    int newIntPart = reverse(intPart);
    double newDecPart = (double)reverse((int)(decPart * 1000)) / 1000;
    double newNum = (double)newIntPart + newDecPart + num;

    printf("%.3lf", newNum);

    return 0;
}
