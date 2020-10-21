#include <stdio.h>

char map[8][8];

void fillUp(int x, int y)
{
    int i = 1;
    while(map[x][y + i] == '_') {
        map[x][y + i] = '=';
        i++;
    }
    i = -1;
    while(map[x][y + i] == '_') {
        map[x][y + i] = '=';
        i--;
    }
    i = 1;
    while(map[x + i][y] == '_') {
        map[x + i][y] = '=';
        i++;
    }
    i = -1;
    while(map[x + i][y] == '_') {
        map[x + i][y] = '=';
        i--;
    }
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    for(int i = 1; i <= 6; i++)
        for(int j = 1; j <= 6; j++)
            scanf(" %c", &map[i][j]);

    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            if(map[i][j] == 'o') {
                fillUp(i, j);
            }
        }
    }

    for(int i = 1; i <= 6; i++) {
        printf("%c", map[i][1]);
        for(int j = 2; j <= 6; j++)
            printf(" %c", map[i][j]);
        printf("\n");
    }

    return 0;
}
