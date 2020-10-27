#include <stdio.h>

long long fastPower(long long x, long long y, long long m)
{
    if(y == 0) return 1 % m;

    long long temp = fastPower(x, y / 2, m);

    if(y & 1)
        return (((temp * temp) % m) * (x % m)) % m;
    else
        return (temp * temp) % m;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    long long x, y, m;
    scanf("%lld %lld %lld", &x, &y, &m);

    printf("%lld\n", fastPower(x, y, m));

    return 0;
}
