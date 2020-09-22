#include <stdio.h>
#include "function.h"

#define for RF
#define while RF
#define goto RF

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
