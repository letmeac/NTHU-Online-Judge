#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char alph[6];
    scanf("%5s", alph);
    int i;
    for(i = 0; i < 5; i++)
        alph[i] = 25 - (alph[i] - 'a') + 'a';
    printf("%s\n", alph);

    return 0;
}
