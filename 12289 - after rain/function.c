#include "function.h"
#include <stdlib.h>
#include <string.h>

void insert(Node** head, char* color, int dest)
{
    Node* nowNode = *head;
    while(dest-- > 0) {
        if(nowNode->next == NULL) break;
        nowNode = nowNode->next;
    }

    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->color, color);
    newNode->next = nowNode->next;
    nowNode->next = newNode;
}

void erase1(Node** head, int dest)
{
    if((*head)->next == NULL) return;

    Node* nowNode = *head;
    while(--dest > 0) {
        if(nowNode->next->next == NULL) break;
        nowNode = nowNode->next;
    }

    Node* tempNode = nowNode->next;
    nowNode->next = tempNode->next;
    free(tempNode);
}

void erase2(Node** head, char* color)
{
    Node* nowNode = *head;
    while(nowNode->next != NULL) {
        if(!strcmp(nowNode->next->color, color)) {
            Node* tempNode = nowNode->next;
            nowNode->next = tempNode->next;
            free(tempNode);
        }
        else {
            nowNode = nowNode->next;
        }
    }
}

void reverse(Node** head, int dest1, int dest2)
{
    dest2 -= dest1;

    Node* node1 = *head;
    while(--dest1 > 0) {
        if(node1->next == NULL) return;
        node1 = node1->next;
    }
    if(node1->next == NULL) return;
    Node* node2 = node1->next;

    Node* preNode = node2;
    Node* nowNode = node2->next;

    while(dest2-- > 0) {
        if(nowNode == NULL) return;
        node1->next = nowNode;
        node2->next = nowNode->next;
        nowNode->next = preNode;
        preNode = nowNode;
        nowNode = node2->next;
    }
}
