#include <stdlib.h>
#include "function.h"

#define RED 0
#define BLUE 1

#define EVEN 0
#define ODD 1

int compare(const void *a, const void *b)
{
    Floor *floor_a = (Floor*)a;
    Floor *floor_b = (Floor*)b;

    return (floor_a->size < floor_b->size) - (floor_a->size > floor_b->size);
}

int design(int floorNum, Floor floorArr[])
{
    int height, color, parity;
    int idx;

    qsort(floorArr, floorNum, sizeof(Floor), compare);

    height = 0;
    color = (floorArr[0].color == 'B')? BLUE: RED;
    parity = (floorArr[0].size % 2 == 0)? EVEN: ODD;

    for(idx = 0; idx < floorNum; idx++) {
        if(color == BLUE && floorArr[idx].color == 'B') {
            if(parity == EVEN && floorArr[idx].size % 2 == 0) {
                height++;
                color = RED;
                parity = ODD;
            }
            else if(parity == ODD && floorArr[idx].size % 2 == 1) {
                height++;
                color = RED;
                parity = EVEN;
            }
        }
        else if(color == RED && floorArr[idx].color == 'R') {
            if(parity == EVEN && floorArr[idx].size % 2 == 0) {
                height++;
                color = BLUE;
                parity = ODD;
            }
            else if(parity == ODD && floorArr[idx].size % 2 == 1) {
                height++;
                color = BLUE;
                parity = EVEN;
            }
        }
    }

    return height;
}
