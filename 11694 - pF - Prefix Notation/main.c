#include <stdio.h>
#include <ctype.h>

float calculate(void);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    printf("%.3f", calculate());

    return 0;
}

float calculate(void)
{
    char ch;
    float op1, op2;
    float ans = 0.;

    ch = getchar();
    if(ch == '+') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 + op2;
    }
    else if(ch == '-') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 - op2;
    }
    else if(ch == '*') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 * op2;
    }
    else if(ch == '/') {
        op1 = calculate();
        op2 = calculate();
        ans = op1 / op2;
    }
    else if(isdigit(ch)) {
        ans = ch - '0';
    }

    return ans;
}
