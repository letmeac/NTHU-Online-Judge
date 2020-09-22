#include <stdio.h>

#define INF 1 << 20
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define ECCIOA 'e'
#define ROAD '.'
#define LAVA '^'
#define WATER '~'

int Row, Col;
char Map[1001][1001];

int MinDist = INF;
void FindWater(int row, int col, int dist);

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

    FindWater(eccioa_x, eccioa_y, 0);

    if(MinDist != INF)
        printf("Alive!\n%d\n", MinDist);
    else
        printf("Dead!\n");

    return 0;
}

void FindWater(int row, int col, int dist)
{
    if(Map[row][col] == LAVA) return;

    if(Map[row][col] == WATER) {
        MinDist = min(MinDist, dist);
        return;
    }

    Map[row][col] = LAVA;
    dist++;

    // change order may get wrong
    // should use BFS instead of DFS
    if(row + 1 < Row) FindWater(row + 1, col, dist);
    if(row - 1 >= 0) FindWater(row - 1, col, dist);
    if(col + 1 < Col) FindWater(row, col + 1, dist);
    if(col - 1 >= 0) FindWater(row, col - 1, dist);
}
