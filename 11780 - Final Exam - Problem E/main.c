#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        char str1[101];
        char str2[101];
        scanf("%s %s", str1, str2);

        int strLength = strlen(str1);

        int i, j;
        int exist = 0;

        char strRotate[202];
        strcpy(strRotate, str1);
        strcat(strRotate, str1);

        for(i = 0; i < strLength; i++) {

            int same = 1;

            for(j = i; j < i + strLength; j++) {
                if(strRotate[j] != str2[j - i]) {
                    same = 0;
                    break;
                }
            }

            if(same) {
                exist = 1;
                break;
            }
        }

        if(exist)
            printf("Yes\n");
        else
            printf("No\n");

    }

    return 0;
}
