#include <stdio.h>
#include "function.h"

/* 
 * n : rest disks on source rod
 * A : source rod
 * B : buffer rod
 * C : destination rod
 * 
 */

void hanoi(int n, char A, char B, char C)
{
    if(n == 0) return;

    // move top n-1 disks from rod A to rod B using rod C as buffer rod
    hanoi(n - 1, A, C, B);

    // move the last disk from rod A to rod C
#ifndef ONLINE_JUDGE
    printf("move disk %d from rod %c to rod %c\n", n, A, C);
#else
    printf("%d\n", n);
#endif

    // move the rest n-1 disks from rod B to rod C using rod A as buffer rod
    hanoi(n - 1, B, A, C);
}
