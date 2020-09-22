#include <stdio.h>
#include "function.h"

#define WAY2

void Transpose(int* row, int* col, int matrix[][500])
{

#ifdef WAY1

    int i, j;
    int transposed[500][500];

    for(i = 0; i < *row; i++) {
        for(j = 0; j < *col; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    int temp = *row;
    *row = *col;
    *col = temp;

    for(i = 0; i < *row; i++) {
        for(j = 0; j < *col; j++) {
            matrix[i][j] = transposed[i][j];
        }
    }

#endif

#ifdef WAY2

    int i, j;
    for(i = 0; i < *col; i++) {
        for(j = 0; j < *row; j++) {
            if(j == *row - 1)
                printf("%d\n", matrix[j][i]);
            else
                printf("%d ", matrix[j][i]);
        }
    }

    *row = 0;
    *col = 0;

#endif

}
