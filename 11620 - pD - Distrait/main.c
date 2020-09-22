#include <stdio.h>

#define SIZE 5
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int card[SIZE][SIZE];

    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%d", &card[i][j]);
        }
    }

    int cases, casesCount;
    scanf("%d", &cases);

    for(casesCount = 1; casesCount <= cases; casesCount++) {

        int checkTime[SIZE][SIZE] = {0};

        int checkCount;
        scanf("%d", &checkCount);

        if(checkCount < 5) {
            printf("Case #%d: Not yet \\(^o^)/\n", casesCount);
            int checkNum;
            while(checkCount-- > 0) scanf("%d", &checkNum);
            continue;
        }

        int time;
        for(time = 1; time <= checkCount; time++) {

            int checkNum;
            scanf("%d", &checkNum);

            // find the number
            for(i = 0; i < SIZE; i++) {
                for(j = 0; j < SIZE; j++) {
                    if(card[i][j] == checkNum) {
                        checkTime[i][j] = time;
                    }
                }
            }
        }

        // check if bingo
        int bingo = 0;
        int bingoTime = checkCount;

        // check row
        for(i = 0; i < SIZE; i++) {
            int bingoRow = 1;
            int bingoRowTime = 0;
            for(j = 0; j < SIZE; j++) {
                if(checkTime[i][j]) {
                    bingoRowTime = max(bingoRowTime, checkTime[i][j]);
                }
                else {
                    bingoRow = 0;
                    break;
                }
            }
            if(bingoRow) {
                bingo = 1;
                bingoTime = min(bingoTime, bingoRowTime);
            }
        }

        // check column
        for(j = 0; j < SIZE; j++) {
            int bingoCol = 1;
            int bingoColTime = 0;
            for(i = 0; i < SIZE; i++) {
                if(checkTime[i][j]) {
                    bingoColTime = max(bingoColTime, checkTime[i][j]);
                }
                else {
                    bingoCol = 0;
                    break;
                }
            }
            if(bingoCol) {
                bingo = 1;
                bingoTime = min(bingoTime, bingoColTime);
            }
        }

        // check diagnose
        // part 1
        int bingoDiag = 1;
        int bingoDiagTime = 0;
        for(i = 0; i < SIZE; i++) {
            if(checkTime[i][i]) {
                bingoDiagTime = max(bingoDiagTime, checkTime[i][i]);
            }
            else {
                bingoDiag = 0;
                break;
            }
        }
        if(bingoDiag) {
            bingo = 1;
            bingoTime = min(bingoTime, bingoDiagTime);
        }

        // part 2
        bingoDiag = 1;
        bingoDiagTime = 0;
        for(i = 0; i < SIZE; i++) {
            if(checkTime[i][SIZE-i-1]) {
                bingoDiagTime = max(bingoDiagTime, checkTime[i][SIZE-i-1]);
            }
            else {
                bingoDiag = 0;
                break;
            }
        }
        if(bingoDiag) {
            bingo = 1;
            bingoTime = min(bingoTime, bingoDiagTime);
        }

        if(bingo) {
            printf("Case #%d: %d\n", casesCount, bingoTime);
        }
        else {
            printf("Case #%d: Not yet \\(^o^)/\n", casesCount);
        }

    }

    return 0;
}
