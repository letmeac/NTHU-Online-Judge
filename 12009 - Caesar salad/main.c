#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char str[4];
    int numShift;
    scanf("%3s %d", str, &numShift);

    int strLen = strlen(str);
    for(int i = 0; i < strLen; i++)
        str[i] = (str[i] - 'A' + numShift % 26 + 26 + 26) % 26 + 'A';

    printf("%s\n", str);

    return 0;
}
