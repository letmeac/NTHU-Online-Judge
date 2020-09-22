#include <stdio.h>

#define INF 1 << 20

#define START 'S'
#define FINAL 'F'
#define ROAD '$'
#define WALL '#'

int Row, Col;
char Maze[501][501];

int MinCost = INF;
void FindPath(int start_x, int start_y);

typedef struct
{
    int x;
    int y;
    int cost;
} Point;

typedef struct
{
    Point *arr;
    int front;
    int back;
} Queue;
void QueueInit(Queue *queue);
void Push(Queue *queue, Point point);
Point Pop(Queue *queue);
int Empty(Queue *queue);
void Free(Queue *queue);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        scanf("%d %d", &Row, &Col);

        int i, j;
        int start_x = -1, start_y = -1;

        for(i = 0; i < Row; i++) {
            scanf("%s", Maze[i]);
        }

        for(i = 0; i < Row; i++) {
            for(j = 0; j < Col; j++) {
                if(Maze[i][j] == START) {
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
            if(start_x != -1) break;
        }

        FindPath(start_x, start_y);

        if(MinCost != INF)
            printf("%d\n", MinCost);
        else
            printf("-1\n");
        
        MinCost = INF;
    }

    return 0;
}

void FindPath(int start_x, int start_y)
{
    int rowDir[4] = {1, -1, 0, 0};
    int colDir[4] = {0, 0, 1, -1};

    Queue queue;
    QueueInit(&queue);

    Maze[start_x][start_y] = WALL;

    Point startPoint = {start_x, start_y, 0};
    Push(&queue, startPoint);

    while(!Empty(&queue)) {

        Point nowPoint = Pop(&queue);

        int i;
        for(i = 0; i < 4; i++) {

            int nextPoint_x = nowPoint.x + rowDir[i];
            int nextPoint_y = nowPoint.y + colDir[i];

            if(nextPoint_x >= 0 && nextPoint_x < Row && nextPoint_y >= 0 && nextPoint_y < Col) {
                if(Maze[nextPoint_x][nextPoint_y] == FINAL) {
                    MinCost = nowPoint.cost + 1;
                    Free(&queue);
                    return;
                }
                else if(Maze[nextPoint_x][nextPoint_y] == ROAD) {
                    Maze[nextPoint_x][nextPoint_y] = WALL;
                    Point nextPoint = {nextPoint_x, nextPoint_y, nowPoint.cost + 1};
                    Push(&queue, nextPoint);
                }
            }

        }

    }

    Free(&queue);
}

void QueueInit(Queue *queue)
{
    queue->front = 0;
    queue->back = 0;
    queue->arr = malloc(250000 * sizeof(Point));
}

void Push(Queue *queue, Point point)
{
    queue->arr[++queue->back] = point;
}

Point Pop(Queue *queue)
{
    return queue->arr[++queue->front];
}

int Empty(Queue *queue)
{
    return queue->front == queue->back;
}

void Free(Queue *queue)
{
    free(queue->arr);
}
