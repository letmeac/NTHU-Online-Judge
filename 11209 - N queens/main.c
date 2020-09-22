#include <stdio.h>

int NumQueen;
int ColOfQueen[10];
int Chess[10][10];
int NumWays;

void PlaceQueen(int queen);
int Valid(int queen, int col);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d", &NumQueen);

    PlaceQueen(0);

    printf("%d", NumWays);

    return 0;
}

void PlaceQueen(int queen)
{
    /*
     * fix nth queen in nth row
     * find valid column to place it
     * 
     */

    if(queen == NumQueen) {
        NumWays++;
    }
    else {

        int col;
        for(col = 0; col < NumQueen; col++) {

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
