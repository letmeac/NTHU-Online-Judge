#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num, pattern;
    scanf("%d %d", &num, &pattern);

    if(pattern == 1) {
        for(int i = num; i >= 1; i--) {
            for(int j = 1; j <= i; j++)
                printf("%d", i);
            printf("\n");
        }
    }
    else if(pattern == 2) {
        for(int i = num; i >= 1; i--) {
            for(int j = i; j >= 1; j--)
                printf("%d", j);
            printf("\n");
        }
    }
    else printf("Unrecognized pattern!\n");

    return 0;
}
