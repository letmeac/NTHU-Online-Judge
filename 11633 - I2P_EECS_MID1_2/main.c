#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char str1[1001];
    char str2[1001];

    while(scanf("%s %s", str1, str2) != EOF) {
        
        int str1Length = strlen(str1);
        int str2Length = strlen(str2);

        /*
         * longest commom subsequence (Dynamic Programming)
         * 
         * str1 = substr1 + endstr1
         * str2 = substr2 + endstr2
         * 
         * LCS(str1, str2) = max{ LCS(substr1, str2), LCS(str1, substr2) }, when endstr1 != endstr2
         *                 = LCS(substr1, substr2) + endstr1,               when endstr1 == endstr2
         * 
         * but this question is "substring" (contiguous sequence)
         * should be modified a little bit
         * 
         */

        int i, j;
        int LCS[1001][1001];
        int maxStrLength = 0;

        for(i = 0; i <= str1Length; i++) {
            for(j = 0; j <= str2Length; j++) {
                if(i == 0 || j == 0) {
                    LCS[i][j] = 0;
                }
                else if(str1[i-1] == str2[j-1]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                    maxStrLength = max(maxStrLength, LCS[i][j]);
                }
                else {
                    LCS[i][j] = 0;
                }
            }
        }

        printf("%d\n", maxStrLength);
    }

    return 0;
}
