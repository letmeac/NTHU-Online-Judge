#include <stdio.h>

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        long long num, x1, x2, x3;
        scanf("%lld %lld %lld %lld", &num, &x1, &x2, &x3);

        long long gcd_x1 = gcd(num, x1);
        long long gcd_x2 = gcd(num, x2);
        long long gcd_x3 = gcd(num, x3);

        long long lcm_all = lcm(lcm(gcd_x1, gcd_x2), gcd_x3);

        printf("%lld\n", num / lcm_all);
    }

    return 0;
}

long long gcd(long long a, long long b)
{
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    // return a * b / gcd(a, b)  (will out of range)
    return (a / gcd(a, b)) * b;
}
