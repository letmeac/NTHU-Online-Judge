#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int dim;
    scanf("%d", &dim);

    int i, j;

    for(i = 0; i < dim; i++) {
        for(j = 0; j < dim; j++) {
            if(i == j)
                printf("%3d", 2);
            else if(j - i == 1 || i - j == 1)
                printf("%3d", -1);
            else
                printf("%3d", 0);
        }
        printf("\n");
    }

    return 0;
}
