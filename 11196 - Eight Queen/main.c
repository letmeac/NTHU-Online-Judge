#include <stdio.h>

#define NUMQUEEN 8
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxScore;
int ChessScore[NUMQUEEN][NUMQUEEN];
int ColOfQueen[NUMQUEEN];

void PlaceQueen(int queen);
int Valid(int queen, int col);
void UpdateScore(void);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int i, j;
        for(i = 0; i < NUMQUEEN; i++){
            for(j = 0; j < NUMQUEEN; j++) {
                scanf("%d", &ChessScore[i][j]);
            }
        }

        maxScore = 0;

        PlaceQueen(0);

        printf("%d\n", maxScore);
    }

    return 0;
}

void PlaceQueen(int queen)
{
    /*
     * fix nth queen in nth row
     * find valid column to place it
     * 
     */

    if(queen == NUMQUEEN) {
        UpdateScore();
    }
    else {

        int col;
        for(col = 0; col < NUMQUEEN; col++) {

            if(Valid(queen, col)) {
                ColOfQueen[queen] = col;
                PlaceQueen(queen+1);
            }
        }
    }
}

int Valid(int queen, int col)
{
    int i;
    for(i = 0; i < queen; i++) {
        if((ColOfQueen[i] == col) || (queen - i == col - ColOfQueen[i]) || (queen - i == ColOfQueen[i] - col)) {
            return 0;
        }
    }

    return 1;
}

void UpdateScore(void)
{
    int i;
    int score = 0;
    for(i = 0; i < NUMQUEEN; i++) {
        score += ChessScore[i][ColOfQueen[i]];
    }

    maxScore = max(maxScore, score);
}
