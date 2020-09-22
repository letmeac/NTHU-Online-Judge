#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char target[5];
    char str[10];
    int targetLength, strLength;
    int maxOccur = 0;

    scanf("%s", target);
    targetLength = strlen(target);

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        scanf("%s", str);
        strLength = strlen(str);

        int i;
        int sameCount = 0;

        for(i = 0; i < strLength - targetLength + 1; i++) {
            int strNowDigit = i;
            int targetNowDigit = 0;
            while(str[strNowDigit] == target[targetNowDigit]) {
                if(targetNowDigit == targetLength - 1) {
                    sameCount++;
                    break;
                }
                strNowDigit++;
                targetNowDigit++;
            }
        }

        if(sameCount > maxOccur) maxOccur = sameCount;
    }

    printf("%d", maxOccur);

    return 0;
}
