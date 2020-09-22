#include <stdio.h>
#include <string.h>

char str1[25];
char str2[25];
int str1Length;
int str2Length;
int matchPoint;

void FindMatchPoint(int index1, int index2);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    while(scanf("%s %s", str1, str2) != EOF) {

        str1Length = strlen(str1);
        str2Length = strlen(str2);

        matchPoint = 0;

        FindMatchPoint(0, 0);

        printf("%d\n", matchPoint);
    }

    return 0;
}

void FindMatchPoint(int index1, int index2)
{
    if(index2 == str2Length) {
        matchPoint++;
        return;
    }

    int i;
    for(i = index1; i < str1Length; i++) {
        if(str1[i] == str2[index2]) {
            FindMatchPoint(i + 1, index2 + 1);
        }
    }
}
