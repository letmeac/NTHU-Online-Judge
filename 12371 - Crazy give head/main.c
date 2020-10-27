#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char str_S[1001];
    char str_p[1001];

    while(scanf("%1000s %1000s", str_S, str_p) != EOF) {

        int strLength_S = strlen(str_S);
        int strLength_p = strlen(str_p);

        int prefixCount[1001];
        prefixCount[0] = 0;

        for(int i = 0; i < strLength_S - strLength_p + 1; i++) {
            int matchCount = 0;
            for(int j = 0; j < strLength_p; j++) {
                if(str_S[i + j] == str_p[j])
                    matchCount++;
                else break;
            }
            if(matchCount == strLength_p)
                prefixCount[i + 1] = prefixCount[i] + 1;
            else
                prefixCount[i + 1] = prefixCount[i];
        }

        int maxSum = 0;

        int queryNum;
        scanf("%d", &queryNum);

        while(queryNum-- > 0) {
            int a, b;
            scanf("%d %d", &a, &b);

            if(b - a + 1 >= strLength_p) {
                int temp = prefixCount[b - strLength_p + 1] - prefixCount[a - 1];
                if(temp > maxSum) maxSum = temp;
            }
        }

        printf("%d\n", maxSum);
    }

    return 0;
}
