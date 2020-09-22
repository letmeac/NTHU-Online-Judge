#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n, m, p;

    while(scanf("%d %d %d", &n, &m, &p) != EOF) {

        int i, j, k;
        long long nm[100][100] = {0};
        long long mp[100][100] = {0};
        long long np[100][100] = {0};

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf("%lld", &nm[i][j]);
            }
        }

        for(i = 0; i < m; i++) {
            for(j = 0; j < p; j++) {
                scanf("%lld", &mp[i][j]);
            }
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < p; j++) {
                for(k = 0; k < m; k++) {
                    np[i][j] += nm[i][k] * mp[k][j];
                }
                printf("%lld", np[i][j]);
                if(j < p - 1) printf(" ");
            }
            printf("\n");
        }

        printf("\n");

    }

    return 0;
}
