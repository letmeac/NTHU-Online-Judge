#include <stdio.h>
#include "function.h"

#define STONE 'S'
#define HOLE 'H'
#define WATER 'W'

// DFS
void flooding(int pr, int pc)
{
    if(Map[pr][pc] == HOLE) {

        Map[pr][pc] = WATER;

        flooding(pr + 1, pc);
        flooding(pr - 1, pc);
        flooding(pr, pc + 1);
        flooding(pr, pc - 1);

    }
}
