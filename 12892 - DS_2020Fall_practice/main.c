#include <stdio.h>

int arr[200000];

int searchIndex(int l, int r, int target)
{
    int mid;
    while(l <= r) {
        mid = l + (r - l) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    int target;
    while(scanf("%d", &target) != EOF) {
        printf("%d\n", searchIndex(0, num - 1, target));
    }

    return 0;
}
