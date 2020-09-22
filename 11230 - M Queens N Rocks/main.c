#include <stdio.h>
#include <stdlib.h>

#define QUEEN 1
#define ROCK 2

int numQueens, numRocks;
int boardSize;
int res = 0;
int ColOfChess[10];
int TypeOfChess[10];

int valid(int row, int col, int chess) {
    int i;
    for(i = 0; i < row; i++) {
        if(TypeOfChess[i] == ROCK && chess == ROCK) {
            if(ColOfChess[i] == col)
                return 0;
        }
        else if(ColOfChess[i] == col || abs(row - i) == abs(ColOfChess[i] - col)) {
            return 0;
        }
    }
    return 1;
}

void putChess(int restQueens, int restRocks, int nowRow) {
    if(nowRow == boardSize && restQueens == 0 && restQueens == 0) {
        res++;
        return;
    }
    int nowCol;
    if(restQueens > 0) {
        for(nowCol = 0; nowCol < boardSize; nowCol++) {
            if(valid(nowRow, nowCol, QUEEN)) {
                ColOfChess[nowRow] = nowCol;
                TypeOfChess[nowRow] = QUEEN;
                putChess(restQueens - 1, restRocks, nowRow + 1);
            }
        }
    }
    if(restRocks > 0) {
        for(nowCol = 0; nowCol < boardSize; nowCol++) {
            if(valid(nowRow, nowCol, ROCK)) {
                ColOfChess[nowRow] = nowCol;
                TypeOfChess[nowRow] = ROCK;
                putChess(restQueens, restRocks - 1, nowRow + 1);
            }
        }
    }
    
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d", &numQueens, &numRocks);
    boardSize = numQueens + numRocks;

    putChess(numQueens, numRocks, 0);

    printf("%d\n", res);

    return 0;
}
