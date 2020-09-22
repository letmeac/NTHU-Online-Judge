#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num, reqNum;
    scanf("%d %d", &num, &reqNum);

    int apr[200001] = {0};  // record the number appear in request or not
    int req[100000] = {0};

    int i;
    for(i = 0; i < reqNum; i++) {
        scanf("%d", &req[i]);
    }

    for(i = reqNum-1; i >= 0; i--) {
        if(!apr[req[i]]) {
            printf("%d\n", req[i]);
            apr[req[i]] = 1;
        }
    }

    for(i = 1; i <= num; i++) {
        if(!apr[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
