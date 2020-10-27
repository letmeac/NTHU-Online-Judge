#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int map[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &map[i][j]);

    int x, y;
    scanf("%d %d", &x, &y);

    int smallCard = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(map[i][j] < map[x][y])
                smallCard++;

    printf("%.3f\n", (float)smallCard / 8);

    return 0;
}
