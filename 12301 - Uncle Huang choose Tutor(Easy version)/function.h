#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int number;
    struct _Node* next;
} Node;

Node* createList(int n);
void freeList(Node* head);
int solveJosephus(Node** head, int step);

#endif
