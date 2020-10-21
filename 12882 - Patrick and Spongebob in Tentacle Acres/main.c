#include <stdio.h>

int map[500][500];

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    int step = 1;
    int col = 0;
    while(col < m) {
        int row = 0;
        while(row < n)
            map[row++][col] = step++;
        col++;
        while(--row >= 0)
            map[row][col] = step++;
        col++;
    }

    for(int i = 0; i < n; i++) {
        printf("%d", map[i][0]);
        for(int j = 1; j < m; j++)
            printf(" %d", map[i][j]);
        printf("\n");
    }

    return 0;
}
