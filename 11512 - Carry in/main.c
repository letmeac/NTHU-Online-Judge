#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char num1[1001];
    char num2[1001];

    while(scanf("%s %s", num1, num2) != EOF) {

        int num1Length = strlen(num1);
        int num2Length = strlen(num2);

        int carryCount = 0;
        int carry = 0;

        int i = num1Length - 1;
        int j = num2Length - 1;

        while(i >= 0 || j >= 0) {

            if(i >= 0) carry += num1[i--] - '0';
            if(j >= 0) carry += num2[j--] - '0';

            if(carry >= 10) {
                carryCount++;
                carry = 1;
            }
            else carry = 0;

        }

        printf("%d\n", carryCount);

    }

    return 0;
}
