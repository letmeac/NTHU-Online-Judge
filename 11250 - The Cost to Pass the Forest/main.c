#include <stdio.h>

#define INF 1 << 20
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define START 'S'
#define DEST 'T'
#define PASSWAY '#'
#define TREE '*'

int Row, Col;
char Map[101][101];

int MinCost = INF;
void FindPath(int row, int col, int cost);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d", &Row, &Col);

    int i, j;
    int start_x = -1, start_y = -1;

    for(i = 0; i < Row; i++) {
        scanf("%s", Map[i]);
    }

    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            if(Map[i][j] == START) {
                start_x = i;
                start_y = j;
                break;
            }
        }
        if(start_x != -1) break;
    }

    FindPath(start_x, start_y, 0);

    if(MinCost != INF)
        printf("%d\n", MinCost);
    else
        printf("0\n");

    return 0;
}

void FindPath(int row, int col, int cost)
{
    if(Map[row][col] == TREE) return;

    if(Map[row][col] == DEST) {
        MinCost = min(MinCost, cost);
        return;
    }

    Map[row][col] = TREE;
    cost++;

    // change order may get wrong
    // should use BFS instead of DFS
    if(row + 1 < Row) FindPath(row + 1, col, cost);
    if(row - 1 >= 0) FindPath(row - 1, col, cost);
    if(col + 1 < Col) FindPath(row, col + 1, cost);
    if(col - 1 >= 0) FindPath(row, col - 1, cost);
}
