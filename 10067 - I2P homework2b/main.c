#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b, c;
    scanf("%1d%1d%1d", &a, &b, &c);

    // 1 -> 'A'=65 ... 
    printf("%c%c%c", a+'A'-1, b+'A'-1, c+'A'-1);

    return 0;
}
