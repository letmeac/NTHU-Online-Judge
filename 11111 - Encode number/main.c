#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;

    for(int i = 0; i < 3; i++) {
        scanf("%1d", &num);
        printf("%c", num + 'A' - 1);
    }

    // char code[4];
    // scanf("%3s", code);

    // int i;
    // for(i = 0; i < 3; i++)
    //     code[i] += 'A' - '1';

    // printf("%s", code);

    return 0;
}
