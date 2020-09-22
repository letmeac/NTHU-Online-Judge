#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int** allocateMat(int m, int n)
{
    int i;

    int** mat = malloc(m * sizeof(int*));
    for(i = 0; i < m; i++)
        mat[i] = malloc(n * sizeof(int));

    return mat;
}

void readInput(int** mat, int m, int n)
{
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printResult(int** mat, int m, int n)
{
    int i, j;

    for(j = 0; j < n; j++) {
        for(i = 0; i < m; i++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
