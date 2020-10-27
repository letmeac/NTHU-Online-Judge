#include <stdio.h>
#include <stdlib.h>
#include "function.h"

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

int preorder_idx;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end) return NULL;

    Node* rootNode = malloc(sizeof(Node));
    rootNode->num = preorder[preorder_idx++];

    int inorder_idx = inorder_start;
    for(; inorder_idx <= inorder_end; inorder_idx++) {
        if(rootNode->num == inorder[inorder_idx])
            break;
    }

    rootNode->left = buildTree(inorder, preorder, inorder_start, inorder_idx - 1);
    rootNode->right = buildTree(inorder, preorder, inorder_idx + 1, inorder_end);

    return rootNode;
}

void showPostorder(Node* root)
{
    if(root != NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->num);
    }
}

void freeTree(Node* root)
{
    preorder_idx = 0;
    if(root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
