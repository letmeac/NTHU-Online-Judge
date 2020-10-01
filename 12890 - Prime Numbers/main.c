#include <stdio.h>

char notPrimeNumber[32768];

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    int i;
    for(i = 2; i <= num / 2; i++) {
        if(notPrimeNumber[i]) continue;
        int temp = i * 2;
        while(temp <= num) {
            notPrimeNumber[temp] = 1;
            temp += i;
        }
    }

    printf("2");
    for(i = 3; i <= num; i++)
        if(!notPrimeNumber[i])
            printf(" %d", i);
    printf("\n");

    return 0;
}
