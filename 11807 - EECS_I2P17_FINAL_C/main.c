#include <stdio.h>

#define RED 1
#define BLUE 2

int nodeNum, edgeNum;
int Matrix[1001][1001];

int Bipartite = 1;
int Color[1001];

void DFS(int node);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        scanf("%d %d", &nodeNum, &edgeNum);

        int i, j;
        for(i = 1; i <= nodeNum; i++) {
            for(j = 1; j <= nodeNum; j++) {
                Matrix[i][j] = 0;
            }
        }

        for(i = 1; i <= nodeNum; i++) Color[i] = 0;

        Bipartite = 1;

        for(i = 0; i < edgeNum; i++) {
            int node[2];
            scanf("%d %d", &node[0], &node[1]);
            Matrix[node[0]][node[1]] = 1;
            Matrix[node[1]][node[0]] = 1;
        }

        // use DFS to color the graph
        Color[1] = RED;
        DFS(1);

        if(Bipartite)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

void DFS(int node)
{
    int i;
    for(i = 1; i <= nodeNum; i++) {
        if(node == i) continue;
        if(Matrix[node][i]) {
            if(!Color[i]) {
                Color[i] = 3 - Color[node];
                DFS(i);
            }
            else if(Color[i] == Color[node]) {
                Bipartite = 0;
            }
        }
        if(!Bipartite) return;
    }
}
