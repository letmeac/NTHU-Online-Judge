#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    int tempNum = num;
    int reverseNum = 0;
    while(tempNum) {
        reverseNum = reverseNum * 10 + tempNum % 10;
        tempNum /= 10;
    }

    if(num == reverseNum)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
