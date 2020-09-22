#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    unsigned int days;
    scanf("%u", &days);

    unsigned int years = days / 365;
    unsigned int weeks = (days - years * 365) / 7;
    days = days - years * 365 - weeks * 7;

    printf("%u year(s), %u week(s), %u day(s)\n", years, weeks, days);

    return 0;
}
