#include <stdio.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int calculate(void);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    printf("%d", calculate());

    return 0;
}

int calculate(void)
{
    char ch;
    int op1, op2;
    int ans = 0;

    ch = getchar();
    if(ch == 'M') {
        op1 = calculate();
        op2 = calculate();
        ans = max(op1, op2);
    }
    else if(ch == 'm') {
        op1 = calculate();
        op2 = calculate();
        ans = min(op1, op2);
    }
    else if(isdigit(ch)) {
        ans = ch - '0';
    }

    return ans;
}
