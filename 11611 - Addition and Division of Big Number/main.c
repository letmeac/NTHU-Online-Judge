#include <stdio.h>
#include <string.h>

#define maxLength 1005

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char num1[maxLength];
    char num2[maxLength];
    int divisor;
    char ans[maxLength];

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        memset(num1, 0, maxLength * sizeof(char));
        memset(num2, 0, maxLength * sizeof(char));
        memset(ans, 0, maxLength * sizeof(char));

        scanf("%s", num1);
        scanf("%s", num2);
        scanf("%d", &divisor);

        // for addition
        int i;
        int carry = 0;
        int numLength = strlen(num1);
        ans[numLength + 1] = '\0';

        for(i = numLength - 1; i >= 0; i--) {
            int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
            ans[i + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        ans[0] = carry + '0';

        // for division
        int rest = 0;
        int ansLength = strlen(ans);

        for(i = 0; i < ansLength; i++) {
            int temp = (ans[i] - '0') + 10 * rest;
            ans[i] = temp / divisor + '0';
            rest = temp % divisor;
        }

        // print
        int ansBegin = 0;
        while(ans[ansBegin] == '0' && ansBegin < ansLength-1)  // remain at least 1 digit
            ansBegin++;
 
        printf("%s\n", &ans[ansBegin]);

    }

    return 0;
}
