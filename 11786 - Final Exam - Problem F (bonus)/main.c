#include <stdio.h>
#include <string.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int route;
    scanf("%d", &route);

    int i, j;
    int location[2000];
    int locationNum = 0;

    for(i = 0; i < route; i++) {

        char dir[101];
        scanf("%s", dir);

        int x = 0, y = 0;
        int length = strlen(dir);

        for(j = 0; j < length; j++) {
            if(dir[j] == 'N') y++;
            else if(dir[j] == 'S') y--;
            else if(dir[j] == 'E') x++;
            else if(dir[j] == 'W') x--;
        }

        int position = (x + 100) * 101 + (y + 100);

        for(j = 0; j < locationNum; j++) {
            if(location[j] == position)
                break;
        }

        if(j == locationNum) {
            location[locationNum++] = position;
        }

    }

    printf("%d\n", locationNum);

    return 0;
}
