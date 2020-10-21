#include "function.h"

Node* createList(int n)
{
    Node* head;
    Node** nowNode = &head;

    for(int i = 1; i <= n; i++) {
        *nowNode = malloc(sizeof(Node));
        (*nowNode)->number = i;
        nowNode = &(*nowNode)->next;
    }
    *nowNode = head;

    return head;
}

void freeList(Node* head)
{
    // only one node left
    free(head);

    // while(head != NULL) {
    //     Node* nextNode = head->next;
    //     free(head);
    //     head = nextNode;
    // }
}

int solveJosephus(Node** head, int step)
{
    // find n and let nowNode points to the last node
    int n = 1;
    Node* nowNode = *head;
    while(nowNode->next != *head) {
        nowNode = nowNode->next;
        n++;
    }

    while(nowNode->next != nowNode) {

        // count step-1
        for(int i = 0; i < (step-1) % n; i++) {
            nowNode = nowNode->next;
        }

        // delete the next node
        Node* tempNode = nowNode->next;
        nowNode->next = tempNode->next;
        free(tempNode);

        n--;
    }

    *head = nowNode;

    return nowNode->number;
}
