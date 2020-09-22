#include <stdio.h>

int cityNum;
int matrix[1001][1001];

int Group[1001];
int NowGroup = 1;

void DFS(int city);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int roadNum;
    scanf("%d %d", &cityNum, &roadNum);

    int i;
    for(i = 0; i < roadNum; i++) {
        int city[2];
        scanf("%d %d", &city[0], &city[1]);
        matrix[city[0]][city[1]] = 1;
        matrix[city[1]][city[0]] = 1;
    }

    // use DFS to find connected components
    for(i = 1; i <= cityNum; i++) {
        if(!Group[i]) {
            Group[i] = NowGroup++;
            DFS(i);
        }
    }

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int city[2];
        scanf("%d %d", &city[0], &city[1]);

        if(Group[city[0]] == Group[city[1]]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}

void DFS(int city)
{
    int i;
    for(i = 1; i <= cityNum; i++) {
        if(matrix[city][i] && !Group[i]) {
            Group[i] = Group[city];
            DFS(i);
        }
    }
}
