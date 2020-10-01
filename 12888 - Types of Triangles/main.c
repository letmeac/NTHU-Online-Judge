#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a + b <= c || a + c <= b || b + c <= a)
        printf("Not a triangle\n");
    else if(a == b && b == c)
        printf("Equilateral triangle\n");
    else if(a == b && b != c || b == c && c != a || a == c && c != b)
        printf("Isosceles triangle\n");
    else if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        printf("Right triangle\n");
    else
        printf("General triangle\n");

    return 0;
}
