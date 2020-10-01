#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int minute, hour;
    scanf("%2d %2d", &hour, &minute);

    if(hour < 12)
        printf("%02d:%02d a.m.", hour, minute);
    else
        printf("%02d:%02d p.m.", hour - 12, minute);

    return 0;
}
