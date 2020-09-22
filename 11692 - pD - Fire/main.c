#include <stdio.h>

#define ECCIOA 'e'
#define ROAD '.'
#define LAVA '^'
#define WATER '~'

int Row, Col;
char Map[1001][1001];

int Alive;
void FindWater(int row, int col);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d", &Row, &Col);

    int i, j;
    int eccioa_x = -1, eccioa_y = -1;

    for(i = 0; i < Row; i++) {
        scanf("%s", Map[i]);
    }

    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            if(Map[i][j] == ECCIOA) {
                eccioa_x = i;
                eccioa_y = j;
                break;
            }
        }
        if(eccioa_x != -1) break;
    }

    FindWater(eccioa_x, eccioa_y);

    if(Alive)
        printf("Alive!\n");
    else
        printf("Dead!\n");

    return 0;
}

// DFS
void FindWater(int row, int col)
{
    if(Alive) return;

    if(Map[row][col] == LAVA) return;

    if(Map[row][col] == WATER) {
        Alive = 1;
        return;
    }

    Map[row][col] = LAVA;

    if(row - 1 >= 0) FindWater(row - 1, col);
    if(row + 1 < Row) FindWater(row + 1, col);
    if(col - 1 >= 0) FindWater(row, col - 1);
    if(col + 1 < Col) FindWater(row, col + 1);
}
