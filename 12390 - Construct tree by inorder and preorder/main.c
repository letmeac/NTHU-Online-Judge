#include <stdio.h>
#include "function.h"

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    int id = 1;
    while(scanf("%d", &n) != EOF) {

        int inorder[100], preorder[100];

        for(int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);

        for(int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);

        Node* root = buildTree(inorder, preorder, 0, n - 1);

        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");

        freeTree(root);
    }

    return 0;
}
