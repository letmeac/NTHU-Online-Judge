#include <stdio.h>

typedef struct
{
    int arr[1005];
    int top;
} Stack;
void StackInit(Stack* stack);
int StackTop(Stack* stack);
void StackPush(Stack* stack, int num);
void StackPop(Stack* stack);
int StackEmpty(Stack* stack);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int number;

    while(scanf("%d", &number) != EOF) {

        int i;
        int arr[1000];

        for(i = 0; i < number; i++)
            scanf("%d", &arr[i]);

        Stack stack;
        StackInit(&stack);

        int nowArrPos = 0;
        int nowTarget = 1;
        int permutable = 1;

        while(nowTarget <= number) {

            if(StackTop(&stack) == nowTarget) {
                StackPop(&stack);
                nowTarget++;
            }
            else if(nowArrPos < number && arr[nowArrPos] == nowTarget) {
                nowArrPos++;
                nowTarget++;
            }
            else if(nowArrPos < number) {
                StackPush(&stack, arr[nowArrPos]);
                nowArrPos++;
            }
            else {
                permutable = 0;
                break;
            }

        }

        if(permutable)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}

void StackInit(Stack *stack)
{
    stack->top = 0;
}

int StackTop(Stack* stack)
{
    if(StackEmpty(stack)) return -1;
    return stack->arr[stack->top - 1];
}

void StackPush(Stack *stack, int num)
{
    stack->arr[stack->top++] = num;
}

void StackPop(Stack *stack)
{
    --stack->top;
}

int StackEmpty(Stack *stack)
{
    return stack->top == 0;
}
