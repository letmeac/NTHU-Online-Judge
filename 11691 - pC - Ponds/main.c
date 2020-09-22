#include <stdio.h>

#define WATER '~'
#define LAND '.'

int Row, Col;
char Map[1001][1001];

void UpdateMap(int row, int col);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d", &Row, &Col);

    int i, j;
    for(i = 0; i < Row; i++) {
        scanf("%s", Map[i]);
    }

    int NumPonds = 0;

    // DFS
    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            if(Map[i][j] == WATER) {
                NumPonds++;
                UpdateMap(i, j);
            }
        }
    }

    printf("%d\n", NumPonds);

    return 0;
}

void UpdateMap(int row, int col)
{
    if(Map[row][col] == LAND) return;

    Map[row][col] = LAND;

    if(row - 1 >= 0) UpdateMap(row - 1, col);
    if(row + 1 < Row) UpdateMap(row + 1, col);
    if(col - 1 >= 0) UpdateMap(row, col - 1);
    if(col + 1 < Col) UpdateMap(row, col + 1);
}
