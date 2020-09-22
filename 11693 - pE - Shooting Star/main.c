#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

#define UP 'u'
#define DOWN 'd'

int CeilingLength;
int FloorLength;
int Height;

int RouteLength;

char ShootingRoute[50][50];
void RouteInit(void);
void ShootUp(int row, int col);
void ShootDown(int row, int col);
void ShowRoute(void);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d %d %d", &CeilingLength, &FloorLength, &Height);

    int startPoint;
    char direction;
    scanf("%d %c", &startPoint, &direction);

    RouteInit();

    if(direction == UP)
        ShootUp(startPoint, 0);
    else
        ShootDown(startPoint, 0);

    ShowRoute();

    return 0;
}

void RouteInit(void)
{
    int i, j;
    for(i = 0; i < 50; i++) {
        for(j = 0; j < 50; j++) {
            ShootingRoute[i][j] = ' ';
        }
    }

    for(i = 0; i < CeilingLength; i++) {
        ShootingRoute[0][i] = '-';
    }

    for(i = 0; i < FloorLength; i++) {
        ShootingRoute[Height+1][i] = '-';
    }
}

void ShootUp(int row, int col)
{
    ShootingRoute[row][col] = '*';

    if(row == 0) {
        RouteLength = col + 1;
    }
    else if(row == 1 && ShootingRoute[row - 1][col] == '-') {
        ShootDown(row + 1, col + 1);
    }
    else {
        ShootUp(row - 1, col + 1);
    }
}

void ShootDown(int row, int col)
{
    ShootingRoute[row][col] = '*';

    if(row == Height + 1) {
        RouteLength = col + 1;
    }
    else if(row == Height && ShootingRoute[row + 1][col] == '-') {
        ShootUp(row - 1, col + 1);
    }
    else {
        ShootDown(row + 1, col + 1);
    }
}

void ShowRoute(void)
{
    int i, j;
    int maxHeight = Height + 2;
    int maxLength = max(max(CeilingLength, FloorLength), RouteLength);

    for(i = 0; i < maxHeight; i++) {
        for(j = 0; j < maxLength; j++) {
            printf("%c", ShootingRoute[i][j]);
        }
        printf("\n");
    }
}
