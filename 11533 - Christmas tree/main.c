#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int level, width, height;
    scanf("%d %d %d", &level, &width, &height);

    char star[50];
    memset(star, '*', 50);

    int center = max(level, width / 2 + 1);

    int i;

    for(i = 1; i <= level; i++) {
        printf("%*.*s\n", (center - i) + (2 * i - 1), 2 * i - 1, star);
    }

    for(i = 0; i < height; i++) {
        printf("%*.*s\n", (center - 1) + (width / 2 + 1), width, star);
    }

    return 0;
}
