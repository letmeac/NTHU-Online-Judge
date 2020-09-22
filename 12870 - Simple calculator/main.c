#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    double a, b;
    char op;

    scanf("%lf%c%lf", &a, &op, &b);

    switch(op) {
        case '+':
            printf("%.3lf\n", a + b);
            break;
        case '-':
            printf("%.3lf\n", a - b);
            break;
        case '*':
            printf("%.3lf\n", a * b);
            break;
        case '/':
            if(b == 0)
                printf("Error\n");
            else
                printf("%.3lf\n", a / b);
            break;
    }

    return 0;
}
