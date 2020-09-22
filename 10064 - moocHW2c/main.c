#include <stdio.h>

#define INF 1 << 25
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    int base = 10;
    int minQuotient = INF;

    while(num / base != 0) {

        int num1 = num % base;
        int num2 = num / base;

        if(num1 > num2) {
            if(num1 % num2 == 0) {
                minQuotient = min(minQuotient, num1 / num2);
            }
        }
        else {
            if(num2 % num1 == 0) {
                minQuotient = min(minQuotient, num2 / num1);
            }
        }

        base *= 10;
    }

    if(minQuotient != INF)
        printf("%d\n", minQuotient);
    else
        printf("%d\n", 0);

    return 0;
}
