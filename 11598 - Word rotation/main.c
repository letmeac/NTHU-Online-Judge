#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char word[1001];
    scanf("%s", word);

    int length = strlen(word);

    int i;
    for(i = 0; i < length; i++) {
        printf("%s", word + i + 1);
        printf("%.*s\n", i + 1, word);
    }

    return 0;
}
