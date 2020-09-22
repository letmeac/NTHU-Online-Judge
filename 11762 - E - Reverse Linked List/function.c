#include <stdlib.h>
#include <stdio.h>
#include "function.h"

Node* Create_List(Node* head, int data)
{
    Node* nextNode = malloc(sizeof(Node));
    nextNode->data = data;
    nextNode->next = NULL;

    if(head == NULL) return nextNode;
    else {
        Node* nowNode = head;
        while(nowNode->next != NULL)
            nowNode = nowNode->next;

        nowNode->next = nextNode;
    }

    return head;
}

Node* Reverse_List(Node* head)
{
    if(head == NULL) return head;

    Node* nowNode = head;
    Node* nextNode = head->next;
    nowNode->next = NULL;
    while(nextNode != NULL) {

        Node* thirdNode = nextNode->next;
        nextNode->next = nowNode;

        nowNode = nextNode;
        nextNode = thirdNode;
    }

    return nowNode;
}

void Print_List(Node* head)
{
    while(head != NULL) {

        printf("%d", head->data);

        if(head->next != NULL) printf("->");
        else printf("\n");

        head = head->next;
    }
}

void Free_List(Node* head)
{
    while(head != NULL) {

        Node* nextNode = head->next;

        free(head);

        head = nextNode;
    }
}
