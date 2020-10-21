#include <stdio.h>

// typedef union {
//     float floatNum;
//     unsigned int intNum;
// } Num;

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    // Num num;
    // while(scanf("%f", &num.floatNum) != EOF) {
    //     char bin[32] = {0};
    //     int i = 0;
    //     while(num.intNum) {
    //         bin[i++] = num.intNum & 1;
    //         num.intNum >>= 1;
    //     }
    //     for(i = 31; i >= 0; i--)
    //         printf("%d", bin[i]);
    //     printf("\n");
    // }

    float numFloat;
    while(scanf("%f", &numFloat) != EOF) {
        unsigned int numInt = *(unsigned int*)&numFloat;
        char bin[32] = {0};
        int i = 0;
        while(numInt) {
            bin[i++] = numInt & 1;
            numInt >>= 1;
        }
        for(i = 31; i >= 0; i--)
            printf("%d", bin[i]);
        printf("\n");
    }

    return 0;
}
