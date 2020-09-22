#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int numLayers;
int Tower[10][10];

int FindPath(int layer, int element);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d", &numLayers);

    int i, j;
    for(i = 0; i < numLayers; i++) {
        for(j = 0; j <= i; j++) {
            scanf("%d", &Tower[i][j]);
        }
    }

    printf("%d\n", FindPath(0, 0));

    return 0;
}

int FindPath(int layer, int element)
{
    if(layer == numLayers - 1) return Tower[layer][element];
    return Tower[layer][element] + max(FindPath(layer + 1, element), FindPath(layer + 1, element + 1));
}
