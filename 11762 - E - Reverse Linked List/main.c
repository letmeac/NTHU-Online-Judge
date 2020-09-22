#include <stdio.h>
#include "function.h"

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    Node *head = NULL;
    int n, data, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &data);
        head = Create_List(head, data);
    }

    head = Reverse_List(head);

    Print_List(head);
    Free_List(head);

    return 0;
}
