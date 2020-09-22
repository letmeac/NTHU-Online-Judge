#include <stdio.h>
#include <string.h>

typedef struct
{
    char arr[1005];
    int top;
} Stack;
void StackInit(Stack *stack);
void StackPush(Stack *stack, char ch);
char StackPop(Stack *stack);
int StackEmpty(Stack *stack);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char temp;
    int cases, casesCount;
    scanf("%d%c", &cases, &temp);

    char str[1005];

    for(casesCount = 1; casesCount <= cases; casesCount++) {

        scanf("%c", &str[0]);

        if(str[0] == '\n') {
            printf("Case %d: Yes\n", casesCount);
            continue;
        }

        scanf("%s%c", &str[1], &temp);
        int strLength = strlen(str);

        Stack stack;
        StackInit(&stack);

        int i;
        char par;
        int match = 1;

        for(i = 0; i < strLength; i++) {
            switch(str[i]) {
                case '{': case '[': case '(': case '<':
                    StackPush(&stack, str[i]);
                    break;
                case '}':
                    par = StackPop(&stack);
                    if(par != '{') match = 0;
                    break;
                case ']':
                    par = StackPop(&stack);
                    if(par != '[') match = 0;
                    break;
                case ')':
                    par = StackPop(&stack);
                    if(par != '(') match = 0;
                    break;
                case '>':
                    par = StackPop(&stack);
                    if(par != '<') match = 0;
                    break;
                default:
                    break;
            }
            if(match == 0) break;
        }

        if(match && StackEmpty(&stack))
            printf("Case %d: Yes\n", casesCount);
        else
            printf("Case %d: No\n", casesCount);
    }

    return 0;
}

void StackInit(Stack *stack)
{
    stack->top = 0;
}

void StackPush(Stack *stack, char ch)
{
    stack->arr[stack->top++] = ch;
}

char StackPop(Stack *stack)
{
    if(StackEmpty(stack)) return 0;
    return stack->arr[--stack->top];
}

int StackEmpty(Stack *stack)
{
    return stack->top == 0;
}
