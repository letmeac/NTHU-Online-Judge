#include <stdio.h>

int first4(int x) { return x / 10000; }
int last4(int x) { return x % 10000; }
int first8(int x) { return x / 100000000; }
int last8(int x) { return x % 100000000; }
int shift4(int x) { return x * 10000; }

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int x;
    int a, b;
    int c1, c2, c3;

    scanf("%d", &x);

    // x = a * 10000 + b
    a = first4(x);
    b = last4(x);

    // c3 = (b * b) % 10000
    // c2 = ((b * b) / 10000 + 2 * a * b + ((a * a) % 10000) * 10000) % 100000000
    // c1 = (((b * b) / 10000 + 2 * a * b) / 10000 + a * a) / 10000
    c3 = last4(b * b);
    c2 = last8(first4(b * b) + 2 * a * b + shift4(last4(a * a)));
    c1 = first4(first4(first4(b * b) + 2 * a * b) + a * a);

    printf("%4d%08d%04d", c1, c2, c3);

    return 0;
}
