#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        Node* head;
        head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
        freeList(head);
    }
    return 0;
}
