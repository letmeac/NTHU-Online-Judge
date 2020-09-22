#include <stdio.h>

void hanoi(int n, char A, char B, char C);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

	int n;
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}

void hanoi(int n, char A, char B, char C)
{
    if(n == 0) return;

    // move top n-1 disks from rod A to rod B using rod C as buffer rod
    hanoi(n - 1, A, C, B);

    // move the last disk from rod A to rod C
    printf("move disk %d from rod %c to rod %c\n", n, A, C);

    // move the rest n-1 disks from rod B to rod C using rod A as buffer rod
    hanoi(n - 1, B, A, C);
}
