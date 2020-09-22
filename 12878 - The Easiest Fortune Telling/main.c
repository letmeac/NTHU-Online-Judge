#include <stdio.h>

const char fortune[8][10] = {"", "Xiong", "Mo-Ji", "Mo-Ji", "Xiao-Ji", "Xiao-Ji", "Da-Ji", "Xiao-Ji"};
const int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int M, D;
    scanf("%d %d", &M, &D);

    int i;
    int totalDay = D;
    for(i = 1; i < M; i++)
        totalDay += month[i];

    // 2020/01/01 is Wed (from Mon to Wed => shift by 2)
    printf("%s\n", fortune[(totalDay + 2) % 7]);

    return 0;
}
