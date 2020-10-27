#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char map[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf(" %c", &map[i][j]);

    for(int i = 0; i < 3; i++) {
        if(map[i][0] == map[i][1] && map[i][1] == map[i][2]) {
            printf("%c wins!\n", map[i][0]);
            return 0;
        }
        if(map[0][i] == map[1][i] && map[1][i] == map[2][i]) {
            printf("%c wins!\n", map[0][i]);
            return 0;
        }
    }

    if(map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
        printf("%c wins!\n", map[1][1]);
        return 0;
    }

    if(map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
        printf("%c wins!\n", map[1][1]);
        return 0;
    }

    printf("Draw!\n");

    return 0;
}
