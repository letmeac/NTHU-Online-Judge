#include <stdio.h>
#include <math.h>

void printEquation(char op, int num1, int num2)
{
    switch(op) {
        case '+':
            if(num2 < 0)
                printEquation('-', num1, -num2);
            else
                printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            if(num2 < 0)
                printEquation('+', num1, -num2);
            else
                printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if(num2 == 0)
                printf("NaN\n");
            else
                printf("%d / %d = %d\n", num1, num2, (int)round((double)num1 / num2));
            break;
    }
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num1, num2;
    char op;

    scanf("%c %d %d", &op, &num1, &num2);
    printEquation(op, num1, num2);

    return 0;
}
