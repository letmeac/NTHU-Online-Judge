#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {
        int n, m, t;
        scanf("%d %d %d", &n, &m, &t);

        for(int i = 1; i <= n; i++) {
            if(t <= m) {
                if(i <= t) printf("^");
                else printf("-");
            }
            else if(t >= n) {
                if(i > t - m) printf("^");
                else printf("-");
            }
            else {
                if(i <= t && i > t - m) printf("^");
                else printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}
