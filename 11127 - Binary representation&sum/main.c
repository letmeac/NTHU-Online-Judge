#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);
    num += 1;

    char binArr[20] = {0};
    int size = 0;

    int carryCount = 0;

    while(num) {
        binArr[size++] = num & 1;
        num >>= 1;
    }

    int i;
    for(i = 0; i < size; i++) {
        if(binArr[i] == 0) carryCount++;
        else break;
    }

    for(i = size - 1; i >= 0; i--)
        printf("%d", binArr[i]);
    printf(" %d", carryCount);

    return 0;
}
