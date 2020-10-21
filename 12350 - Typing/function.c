#include "function.h"
#include <stdlib.h>

#define ch character
#define next ptr_to_next_node
#define prev ptr_to_prev_node

Node *head, *tail;

void insert(Node** cursor, char c)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->character = c;
    newNode->next = (*cursor)->next;
    newNode->prev = *cursor;
    if(newNode->next == head) tail = newNode;

    (*cursor)->next->prev = newNode;
    (*cursor)->next = newNode;
}

// delete next
void deletion(Node** cursor)
{
    if(*cursor != tail) {
        Node* tempNode = (*cursor)->next;
        (*cursor)->next = tempNode->next;
        (*cursor)->next->prev = *cursor;
        free(tempNode);
    }
}

// delete self
void backspace(Node** cursor)
{
    if(*cursor != head) {
        Node* tempNode = *cursor;
        *cursor = (*cursor)->prev;
        (*cursor)->next = tempNode->next;
        (*cursor)->next->prev = *cursor;
        free(tempNode);
    }
}

void go_left(Node** cursor, int num)
{
    while(num-- > 0)
        *cursor = (*cursor)->prev;
}

void go_right(Node** cursor, int num)
{
    while(num-- > 0)
        *cursor = (*cursor)->next;
}

void go_home(Node** cursor)
{
    *cursor = head;
}

void go_end(Node** cursor)
{
    *cursor = tail;
}
