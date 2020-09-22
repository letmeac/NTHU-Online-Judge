#include <stdio.h>

/*
 * Top-down DP
 * 
 * Use an array to memorized the result for avoiding recomputing
 * 
 */

int nowStair = 2;
int climbWay[41] = {0, 1, 2};
int ClimbStairs(int stairNum);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int stairNum;
        scanf("%d", &stairNum);

        if(stairNum <= nowStair) {
            printf("%d\n", climbWay[stairNum]);
        }
        else {
            printf("%d\n", ClimbStairs(stairNum));
        }

    }

    return 0;
}

int ClimbStairs(int stairNum)
{
    if(stairNum <= nowStair) return climbWay[stairNum];

    climbWay[stairNum] = ClimbStairs(stairNum-2) + ClimbStairs(stairNum-1);

    nowStair = stairNum;

    return climbWay[stairNum];
}
