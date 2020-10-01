#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int year;
    scanf("%d", &year);

    if(year % 4 != 0)
        printf("Common year\n");
    else if(year % 400 == 0)
        printf("Leap year\n");
    else if(year % 100 == 0)
        printf("Common year\n");
    else
        printf("Leap year\n");

    return 0;
}
