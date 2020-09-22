#include <stdio.h>

#define MAXCONTAINERS 5

int NumContainers;
int size[MAXCONTAINERS];

int ContainerCount[MAXCONTAINERS] = {0};

int MinCount = 1 << 20;
int MinContainerCount[MAXCONTAINERS];

void FillWater(int water, int nowContainer);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d", &NumContainers);

    int i;
    for(i = 0; i < NumContainers; i++) {
        scanf("%d", &size[i]);
    }

    int water;
    scanf("%d", &water);

    FillWater(water, 0);

    printf("(%d", MinContainerCount[0]);
    for(i = 1; i < NumContainers; i++) {
        printf(",%d", MinContainerCount[i]);
    }
    printf(")\n");

    return 0;
}

void FillWater(int water, int nowContainer)
{
    if(nowContainer < NumContainers) {

        if(water == 0) {

            int i, localCount = 0;
            for(i = 0; i < NumContainers; i++)
                localCount += ContainerCount[i];

            if(MinCount > localCount) {
                MinCount = localCount;
                for(i = 0; i < NumContainers; i++)
                    MinContainerCount[i] = ContainerCount[i];
            }
        }
        else if(water > 0) {

            FillWater(water, nowContainer + 1);
            ContainerCount[nowContainer]++;
            FillWater(water - size[nowContainer], nowContainer);
            ContainerCount[nowContainer]--;
        }
    }
}
