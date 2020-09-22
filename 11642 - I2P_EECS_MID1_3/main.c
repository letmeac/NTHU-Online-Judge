#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cityNum, roadNum;
    scanf("%d %d", &cityNum, &roadNum);

    int i, j, k;
    int matrix[1001][1001] = {0};

    for(i = 0; i < roadNum; i++) {
        int city[2];
        scanf("%d %d", &city[0], &city[1]);
        matrix[city[0]][city[1]] = 1;
        matrix[city[1]][city[0]] = 1;
    }

    // APSP
    // but this problem is exactly a finding connected component problem (use DFS)
    for(k = 1; k <= cityNum; k++) {
        for(i = 1; i <= cityNum; i++) {
            if(i == k) continue;
            for(j = 1; j <= cityNum; j++) {
                matrix[i][j] |= matrix[i][k] && matrix[k][j];
            }
        }
    }

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int city[2];
        scanf("%d %d", &city[0], &city[1]);

        if(matrix[city[0]][city[1]]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
