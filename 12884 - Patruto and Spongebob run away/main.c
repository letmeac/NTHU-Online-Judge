#include <stdio.h>

int map[500][500];

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    int step = 1;

    for(int loop = 0; loop < n; loop++) {
        for(int i = loop; i < 2 * n - 1 - loop; i++)
            map[loop][i] = step++;
        for(int i = loop; i < 2 * n - 1 - loop; i++)
            map[i][2 * n - 1 - loop] = step++;
        for(int i = 2 * n - 1 - loop; i > loop; i--)
            map[2 * n - 1 - loop][i] = step++;
        for(int i = 2 * n - 1 - loop; i > loop; i--)
            map[i][loop] = step++;
    }

    for(int i = 0; i < 2 * n; i++) {
        printf("%d", map[i][0]);
        for(int j = 1; j < 2 * n; j++)
            printf(" %d", map[i][j]);
        printf("\n");
    }

    return 0;
}
