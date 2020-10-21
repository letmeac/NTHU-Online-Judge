#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char alph;
    int shift;

    scanf("%c %d", &alph, &shift);
    printf("%c\n", (alph - 'A' - shift + 26) % 26 + 'A');

    return 0;
}
