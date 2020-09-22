#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char wordList[1000][51];

    while(1) {

        int numWord;
        scanf("%d", &numWord);

        if(numWord == 0) break;

        int i;
        for(i = 0; i < numWord; i++)
            scanf("%s", wordList[i]);

        qsort(wordList, numWord, 51 * sizeof(char), (int (*) (const void *, const void *))strcmp);

        for(i = 0; i < numWord; i++)
            printf("%s\n", wordList[i]);
        printf("\n");
    }

    return 0;
}
