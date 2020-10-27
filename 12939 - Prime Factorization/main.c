#include <stdio.h>
#include <math.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    while(num % 2 == 0) {
        printf("2 ");
        num /= 2;
    }

    for(int i = 3; i <= sqrt(num); i += 2) {
        while(num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }

    if(num > 2) printf("%d ", num);
    printf("\n");

    return 0;
}
