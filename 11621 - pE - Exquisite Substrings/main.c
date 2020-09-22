#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char str[2001];

    while(scanf("%s", str) != EOF) {
        
        int strLength = strlen(str);

        int i;
        int left, right;
        int strCount = 0;

        for(i = 0; i < strLength; i++) {

            // odd pattern
            for(left = i - 1, right = i + 1; left >= 0 && right < strLength; left--, right++) {
                if(str[left] == str[right]) strCount++;
                else break;
            }

            // even pattern
            for(left = i, right = i + 1; left >= 0 && right < strLength; left--, right++) {
                if(str[left] == str[right]) strCount++;
                else break;
            }

        }

        printf("%d\n", strCount);
    }

    return 0;
}
