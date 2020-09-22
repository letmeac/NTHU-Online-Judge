#include "function.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))

void execInst(int *ptrArr[], char inst, int param1, int param2)
{
    if(inst == 'S') {
        *ptrArr[param1] = param2;
    }
    else if(inst == 'M') {
        *ptrArr[param1] *= param2;
    }
    else if(inst == 'P') {
        ptrArr[param1] = ptrArr[param2];
    }
}

int findMax(int *ptrArr[], int start, int end)
{
    int i;
    int maxValue = 0;

    for(i = start; i <= end; i++) {
        maxValue = max(maxValue, *ptrArr[i]);
    }

    return maxValue;
}
