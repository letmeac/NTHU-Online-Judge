/*
 * The correct way to find shortest path is use BFS
 * WA because the test case is not correct
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 1 << 20

#define ECCIOA 'e'
#define ROAD '.'
#define LAVA '^'
#define WATER '~'

int Row, Col;
char Map[1001][1001];

int MinDist = INF;
void FindWater(int start_x, int start_y);

typedef struct
{
    int x;
    int y;
    int dist;
} Point;

typedef struct
{
    Point *arr;
    int front;
    int back;
} Queue;
void Queueinit(Queue *queue);
void Push(Queue *queue, Point point);
Point Pop(Queue *queue);
int Empty(Queue *queue);
void Free(Queue *queue);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d", &Row, &Col);

    int i, j;
    int eccioa_x = -1, eccioa_y = -1;

    for(i = 0; i < Row; i++) {
        scanf("%s", Map[i]);
    }

    for(i = 0; i < Row; i++) {
        for(j = 0; j < Col; j++) {
            if(Map[i][j] == ECCIOA) {
                eccioa_x = i;
                eccioa_y = j;
                break;
            }
        }
        if(eccioa_x != -1) break;
    }

    FindWater(eccioa_x, eccioa_y);

    if(MinDist != INF)
        printf("Alive!\n%d\n", MinDist);
    else
        printf("Dead!\n");

    return 0;
}

void FindWater(int start_x, int start_y)
{
    int rowNum[4] = {1, -1, 0, 0};
    int colNum[4] = {0, 0, 1, -1};

    Queue queue;
    Queueinit(&queue);

    Map[start_x][start_y] = LAVA;

    Point startPoint = {start_x, start_y, 0};
    Push(&queue, startPoint);

    while(!Empty(&queue)) {

        Point nowPoint = Pop(&queue);

        int i;
        for(i = 0; i < 4; i++) {

            int nextPoint_x = nowPoint.x + rowNum[i];
            int nextPoint_y = nowPoint.y + colNum[i];

            if(nextPoint_x >= 0 && nextPoint_x < Row && nextPoint_y >= 0 && nextPoint_y < Col) {
                if(Map[nextPoint_x][nextPoint_y] == WATER) {
                    MinDist = nowPoint.dist + 1;
                    Free(&queue);
                    return;
                }
                else if(Map[nextPoint_x][nextPoint_y] == ROAD) {
                    Map[nextPoint_x][nextPoint_y] = LAVA;
                    Point nextPoint = {nextPoint_x, nextPoint_y, nowPoint.dist + 1};
                    Push(&queue, nextPoint);
                }
            }

        }

    }

    Free(&queue);
}

void Queueinit(Queue *queue)
{
    queue->front = 0;
    queue->back = 0;
    queue->arr = malloc(1000000 * sizeof(Point));
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
