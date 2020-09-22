#include <stdio.h>
#include <stdint.h>
#include "function.h"

void Print(int m, int n, int matrix[][500])
{
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1]);
        }
    }
}

int32_t main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int matrix[500][500];

    int row, col;
    scanf("%d %d", &row, &col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Transpose(&row, &col, matrix);

    Print(row, col, matrix);

    return 0;
}
