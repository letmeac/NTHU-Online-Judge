#include <stdio.h>

// num1 > num2 => return 1
// num1 = num2 => return 0
// num1 < num2 => return -1
int compare(int num1[], int num1Length, int num2[], int num2Length)
{
    if(num1Length > num2Length)
        return 1;
    if(num1Length < num2Length)
        return -1;
    for(int i = num1Length - 1; i >= 0; i--) {
        if(num1[i] > num2[i])
            return 1;
        if(num1[i] < num2[i])
            return -1;
    }
    return 0;
}

// perform (num1 - num2)
void substraction(int num1[], int num1Length, int num2[], int num2Length)
{
    int ans[100] = {0};
    for(int i = 0; i < num1Length; i++) {
        ans[i] = num1[i] - num2[i];
        if(ans[i] < 0) {
            ans[i] += 10;
            num1[i + 1]--;
        }
    }
    int i = num1Length - 1;
    while(ans[i] == 0) i--;
    while(i >= 0) printf("%d", ans[i--]);
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int num1[100] = {0};
    int num2[100] = {0};
    int num1Length;
    int num2Length;

    scanf("%d", &num1Length);
    for(int i = num1Length - 1; i >= 0; i--)
        scanf("%1d", &num1[i]);

    scanf("%d", &num2Length);
    for(int i = num2Length - 1; i >= 0; i--)
        scanf("%1d", &num2[i]);

    switch(compare(num1, num1Length, num2, num2Length)) {
        case 1:
            substraction(num1, num1Length, num2, num2Length);
            break;
        case 0:
            printf("0");
            break;
        case -1:
            printf("-");
            substraction(num2, num2Length, num1, num1Length);
            break;
        default:
            break;
    }

    return 0;
}
