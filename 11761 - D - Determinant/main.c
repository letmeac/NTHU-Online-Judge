#include <stdio.h>

long long Det(int n, long long Matrix[10][10]);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    long long matrix[10][10];

    int n;
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    printf("%lld\n", Det(n, matrix));

    return 0;
}

long long Det(int n, long long Matrix[10][10])
{
    long long ans = 0LL;
    long long temp[10][10];

    if(n == 2) {
        ans += Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
    }
    else {
        int i, j, k;
        for(i = 0; i < n; i++) {
            for(j = 1; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if(k == i) continue;
                    else if(k < i)
                        temp[j - 1][k] = Matrix[j][k];
                    else if(k > i)
                        temp[j - 1][k - 1] = Matrix[j][k];
                }
            }
            if(i % 2)
                ans -= Matrix[0][i] * Det(n - 1, temp);
            else
                ans += Matrix[0][i] * Det(n - 1, temp);
        }
    }

    return ans;
}
