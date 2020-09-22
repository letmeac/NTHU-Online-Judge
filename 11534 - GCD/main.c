#include <stdio.h>

int FindGCD(int a, int b);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int num1, num2;
        scanf("%d %d", &num1, &num2);

        printf("%d\n", FindGCD(num1, num2));

    }

    return 0;
}

int FindGCD(int a, int b)
{
    if(a % b == 0) return b;

    return FindGCD(b, a % b);
}
