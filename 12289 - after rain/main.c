#include "function.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int n;
    char buf[100];
    int num1, num2;
    Node* head;

    head = (Node*)malloc(sizeof(Node));  // create an empty node
    memset(head->color, '\0', sizeof(head->color));
    head->next = NULL;

    scanf("%d", &n);
    while(n--) {
        scanf("%s", buf);
        if(!strcmp(buf, "insert")) {
            scanf("%s %d", buf, &num1);
            insert(&head, buf, num1);  // insert <color> <dest>
        }
        else if(!strcmp(buf, "erase1")) {
            scanf("%d", &num1);
            erase1(&head, num1);  // erase1 <dest>
        }
        else if(!strcmp(buf, "erase2")) {
            scanf("%s", buf);
            erase2(&head, buf);  // erase2 <color>
        }
        else if(!strcmp(buf, "reverse")) {
            scanf("%d %d", &num1, &num2);
            reverse(&head, num1, num2);  // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf, "show")) {
            show(&head);
        }
    }

    while(head->next != NULL) {
        Node* tempNode = head;
        head = head->next;
        free(tempNode);
    }
    if(head != NULL)
        free(head);

    return 0;
}

void show(Node** head)
{
    Node* now = (*head)->next;
    while(now != NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}
