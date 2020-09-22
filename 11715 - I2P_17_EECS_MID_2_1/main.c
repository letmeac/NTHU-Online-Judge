#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int dim;
    scanf("%d", &dim);

    int i, j;
    int matrix[500][500];

    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j += 2) {
            scanf("%d %d", &matrix[i][j], &matrix[i][j + 1]);
        }
    }

    for(i = 0; i < dim; i += 2) {
        for(j = 0; j < dim; j += 2) {
            int temp = matrix[i][j + 1];
            matrix[i][j + 1] = matrix[i + 1][j];
            matrix[i + 1][j] = temp;
        }
    }

    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim - 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][dim - 1]);
    }

    return 0;
}
