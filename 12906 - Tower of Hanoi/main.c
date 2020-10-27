#include <stdio.h>

void solveHanoi(int num, char rod1, char rod2, char rod3)
{
    if(num == 0) return;
    solveHanoi(num - 1, rod1, rod3, rod2);
    printf("Disk %d moved from %c to %c\n", num, rod1, rod3);
    solveHanoi(num - 1, rod2, rod1, rod3);
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    solveHanoi(num, 'A', 'B', 'C');

    return 0;
}
