#include <stdio.h>

char map[11][11];

void fillUp(int x, int y)
{
    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(map[i][j] == 'x') continue;
            if(map[i][j] == '_') map[i][j] = '1';
            else map[i][j] += 1;
        }
    }
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            scanf(" %c", &map[i][j]);

    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(map[i][j] == 'x') {
                fillUp(i, j);
            }
        }
    }

    for(int i = 1; i <= 9; i++) {
        printf("%c", map[i][1]);
        for(int j = 2; j <= 9; j++)
            printf(" %c", map[i][j]);
        printf("\n");
    }

    return 0;
}
