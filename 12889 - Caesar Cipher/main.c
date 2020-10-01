#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int numShift;
    char str[2001];
    scanf("%d %2000s", &numShift, str);

    int strLen = strlen(str);
    int i;

    for(i = 0; i < strLen; i++)
        str[i] = (str[i] - 'a' + numShift % 26 + 26 + 26) % 26 + 'a';

    printf("%s\n", str);

    return 0;
}
