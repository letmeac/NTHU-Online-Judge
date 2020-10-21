#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int num;
    struct _Node* prev;
    struct _Node* next;
} Node;

int NodeCount;

void insert(Node* head, int value, int count);
void erase(Node* head, int step);
void move(Node** head, int step);
void show(Node* head);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int initNum;
    scanf("%d", &initNum);

    Node* head = malloc(sizeof(Node));
    head->num = initNum;
    head->next = head->prev = head;
    NodeCount = 1;

    int commandCount;
    char command[10];
    scanf("%d", &commandCount);
    while(commandCount-- > 0) {
        scanf("%s", command);
        if(!strcmp(command, "insert")) {
            int value, count;
            scanf("%d %d", &value, &count);
            insert(head, value, count);
            NodeCount += count;
        }
        else if(!strcmp(command, "erase")) {
            int step;
            scanf("%d", &step);
            erase(head, step);
            NodeCount -= step;
        }
        else if(!strcmp(command, "move")) {
            int step;
            scanf("%d", &step);
            move(&head, step % NodeCount);
        }
        else if(!strcmp(command, "show")) {
            show(head);
        }
    }

    Node* nowNode = head->next;
    while(nowNode != head) {
        Node* tempNode = nowNode;
        nowNode = nowNode->next;
        free(tempNode);
    }
    free(nowNode);

    return 0;
}

void insert(Node* head, int value, int count)
{
    while(count-- > 0) {
        Node* newNode = malloc(sizeof(Node));
        newNode->num = value;
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
    }
}

void erase(Node* head, int step)
{
    while(step-- > 0 && head->next != NULL) {
        Node* tempNode = head->next;
        head->next = tempNode->next;
        head->next->prev = head;
        free(tempNode);
    }
}

void move(Node** head, int step)
{
    if(step > 0) {
        while(step-- > 0)
            *head = (*head)->next;
    }
    else {
        while(step++ < 0)
            *head = (*head)->prev;
    }
}

void show(Node* head)
{
    Node* nowNode = head;
    if(nowNode != NULL)
        printf("%d", nowNode->num);
    while(nowNode->next != head) {
        nowNode = nowNode->next;
        printf(" %d", nowNode->num);
    }
    printf("\n");
}
