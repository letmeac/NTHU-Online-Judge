#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct
{
    int givenDay;
    int deadline;
    int finished;
} Asgmt;

int cmp(const void *a, const void *b);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int NumAsgmt;
    scanf("%d", &NumAsgmt);

    int i;
    int MaxDeadline = 0;
    Asgmt asgmt[100];

    for(i = 0; i < NumAsgmt; i++) {
        scanf("%d %d", &asgmt[i].givenDay, &asgmt[i].deadline);
        asgmt[i].finished = 0;
        MaxDeadline = max(MaxDeadline, asgmt[i].deadline);
    }

    Asgmt* asgmtList[100];

    for(i = 0; i < NumAsgmt; i++) {
        asgmtList[i] = &asgmt[i];
    }

    // sort by deadline (ascending)
    qsort(asgmtList, NumAsgmt, sizeof(Asgmt*), cmp);

    int day;
    int MinFinishedCount = 0;
    int MaxFinishedCount = 0;

    // early deadline => do first => max finished
    for(day = 1; day <= MaxDeadline; day++) {
        for(i = 0; i < NumAsgmt; i++) {
            if(!asgmtList[i]->finished && asgmtList[i]->givenDay <= day && asgmtList[i]->deadline >= day) {
                asgmtList[i]->finished = 1;
                MaxFinishedCount++;
                break;
            }
        }
    }

    for(i = 0; i < NumAsgmt; i++) {
        asgmtList[i]->finished = 0;
    }

    // late deadline => do first => min finished
    for(day = 1; day <= MaxDeadline; day++) {
        for(i = NumAsgmt - 1; i >= 0; i--) {
            if(!asgmtList[i]->finished && asgmtList[i]->givenDay <= day && asgmtList[i]->deadline >= day) {
                asgmtList[i]->finished = 1;
                MinFinishedCount++;
                break;
            }
        }
    }

    printf("%d %d\n", MinFinishedCount, MaxFinishedCount);

    return 0;
}

int cmp(const void *a, const void *b)
{
    Asgmt* asgmt_a = *(Asgmt**)a;
    Asgmt* asgmt_b = *(Asgmt**)b;

    return (asgmt_a->deadline > asgmt_b->deadline) - (asgmt_a->deadline < asgmt_b->deadline);
}
