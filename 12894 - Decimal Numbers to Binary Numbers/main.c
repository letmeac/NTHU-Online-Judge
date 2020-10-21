#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    char binNum[15] = {0};
    int length = 0;
    while(num) {
        binNum[length++] = num & 1;
        num >>= 1;
    }

    if(length == 0) printf("0");
    else {
        while(binNum[length - 1] == 0) length--;
        for(int i = length - 1; i >= 0; i--)
            printf("%d", binNum[i]);
    }
    printf("\n");

    return 0;
}
