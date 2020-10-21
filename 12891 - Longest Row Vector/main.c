#include <stdio.h>
#include <math.h>

int m, n;
int matrix[1000][1000];

void switchVector(int row1, int row2)
{
    for(int j = 0; j < n; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

void addVector(int row1, int row2)
{
    for(int j = 0; j < n; j++)
        matrix[row1][j] += matrix[row2][j];
}

double getLength(int row)
{
    double length = 0;
    for(int j = 0; j < n; j++)
        length += matrix[row][j] * matrix[row][j];
    return sqrt(length);
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int k;
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    while(k-- > 0) {
        int op, i, j;
        scanf("%d %d %d", &op, &i, &j);
        if(op == 0)
            switchVector(i, j);
        else if(op == 1)
            addVector(i, j);
    }

    double maxLength = getLength(0);
    int maxRow = 0;
    for(int i = 1; i < m; i++) {
        double newLength = getLength(i);
        if(maxLength < newLength) {
            maxLength = newLength;
            maxRow = i;
        }
    }
    printf("%d", matrix[maxRow][0]);
    for(int j = 1; j < n; j++)
        printf(" %d", matrix[maxRow][j]);
    printf("\n");

    return 0;
}
