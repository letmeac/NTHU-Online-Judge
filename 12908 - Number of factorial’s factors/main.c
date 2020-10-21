#include <stdio.h>

int factorCount[101];

void findFactor(int num)
{
    while(num != 1) {
        for(int i = 2; i <= num; i++) {
            if(num % i == 0) {
                factorCount[i]++;
                num /= i;
                break;
            }
        }
    }
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++)
        findFactor(i);

    unsigned long long ans = 1;
    for(int i = 2; i <= n; i++)
        ans *= (factorCount[i] + 1);

    printf("%llu", ans);

    return 0;
}
