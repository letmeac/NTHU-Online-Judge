#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int cmp(const void* a, const void* b) {
    char* str1 = (char*)a;
    char* str2 = (char*)b;
    int str1Length = strlen(str1);
    int str2Length = strlen(str2);
    int totalLength = str1Length + str2Length;

    char str1str2[totalLength + 1];
    char str2str1[totalLength + 1];
    memset(str1str2, '\0', totalLength + 1);
    memset(str2str1, '\0', totalLength + 1);

    strcat(str1str2, str1);
    strcat(str1str2, str2);
    strcat(str2str1, str2);
    strcat(str2str1, str1);

    int i;
    for(i = 0; i < totalLength; i++) {
        if(str1str2[i] > str2str1[i])
            return -1;
        else if(str1str2[i] < str2str1[i])
            return 1;
    }

    return 0;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int numCount;
    char bigNum[100][1001];

    while(scanf("%d", &numCount) != EOF) {
        int i;
        for(i = 0; i < numCount; i++)
            scanf("%1000s", bigNum[i]);

        qsort(bigNum, numCount, sizeof(char) * 1001, cmp);

        for(i = 0; i < numCount; i++)
            printf("%s", bigNum[i]);
        printf("\n");
    }

    return 0;
}
