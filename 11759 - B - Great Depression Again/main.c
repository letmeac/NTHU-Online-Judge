#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[25];
    int numCarA;
    int numCarB;
    int numCarA_CarB;
} FAC;

int cmpA_B(const void *a, const void *b);
int cmpA_str(const void *a, const void *b);
int cmpA(const void *a, const void *b);
int cmpB(const void *a, const void *b);

int CalCarNum(FAC* fac[], int front, int mid, int end, int makeCarANum, int makeCarBNum);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int facNum, makeCarANum, makeCarBNum;
    scanf("%d %d %d", &facNum, &makeCarANum, &makeCarBNum);

    int i;
    FAC fac[500];

    for(i = 0; i < facNum; i++) {
        scanf("%s %d %d", fac[i].name, &fac[i].numCarA, &fac[i].numCarB);
        fac[i].numCarA_CarB = fac[i].numCarA - fac[i].numCarB;
    }

    // sort by numCarA_CarB (descending)
    FAC* facAB[500];
    for(i = 0; i < facNum; i++) {
        facAB[i] = &fac[i];
    }

    qsort(facAB, facNum, sizeof(FAC*), cmpA_B);

    if(makeCarANum + makeCarBNum < facNum) {
        // try all possible in the middle to find max
        int mid;
        int maxValue = 0;
        int maxMid;

        for(mid = makeCarANum; mid <= (facNum - makeCarBNum); mid++) {
            int value = CalCarNum(facAB, 0, mid, facNum, makeCarANum, makeCarBNum);
            if(value > maxValue) {
                maxValue = value;
                maxMid = mid;
            }
        }

        qsort(facAB, maxMid, sizeof(FAC*), cmpA);
    }

    qsort(facAB, makeCarANum, sizeof(FAC*), cmpA_str);
    for(i = 0; i < makeCarANum; i++)
        printf("%s\n", facAB[i]->name);

    return 0;
}

int cmpA_B(const void *a, const void *b)
{
    FAC* fac_a = *(FAC**)a;
    FAC* fac_b = *(FAC**)b;

    return (fac_a->numCarA_CarB < fac_b->numCarA_CarB) - (fac_a->numCarA_CarB > fac_b->numCarA_CarB);
}

int cmpA_str(const void *a, const void *b)
{
    FAC* fac_a = *(FAC**)a;
    FAC* fac_b = *(FAC**)b;

    return strcmp(fac_a->name, fac_b->name);
}

int cmpA(const void *a, const void *b)
{
    FAC* fac_a = *(FAC**)a;
    FAC* fac_b = *(FAC**)b;

    return (fac_a->numCarA < fac_b->numCarA) - (fac_a->numCarA > fac_b->numCarA);
}

int cmpB(const void *a, const void *b)
{
    FAC* fac_a = *(FAC**)a;
    FAC* fac_b = *(FAC**)b;

    return (fac_a->numCarB < fac_b->numCarB) - (fac_a->numCarB > fac_b->numCarB);
}

int CalCarNum(FAC* fac[], int front, int mid, int end, int makeCarANum, int makeCarBNum)
{
    int numTestCarA = mid - front;
    int numTestCarB = end - mid;

    FAC* testCarA[numTestCarA];
    FAC* testCarB[numTestCarB];

    int i;

    for(i = 0; i < numTestCarA; i++)
        testCarA[i] = fac[front + i];
    
    for(i = 0; i < numTestCarB; i++)
        testCarB[i] = fac[mid + i];
    
    qsort(testCarA, numTestCarA, sizeof(FAC*), cmpA);
    qsort(testCarB, numTestCarB, sizeof(FAC*), cmpB);

    int value = 0;
    for(i = 0; i < makeCarANum; i++) value += testCarA[i]->numCarA;
    for(i = 0; i < makeCarBNum; i++) value += testCarB[i]->numCarB;

    return value;
}
