#include <stdio.h>

#define MIN_CREDIT 16

int CourseNum;
int CourseCredit[20];

int WithdrawWay;
void WithdrawClass(int nowCourse, int nowCredit, int nowChosenCourse);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d", &CourseNum);

    int i;
    int totalCredit = 0;
    char courseName[101];

    for(i = 0; i < CourseNum; i++) {
        scanf("%s %d", courseName, &CourseCredit[i]);
        totalCredit += CourseCredit[i];
    }

    WithdrawClass(0, totalCredit, CourseNum);

    printf("%d\n", WithdrawWay);

    return 0;
}

void WithdrawClass(int nowCourse, int nowCredit, int nowChosenCourse)
{
    if(nowCredit < MIN_CREDIT) return;

    if(nowCourse == CourseNum) {
        if(nowChosenCourse < CourseNum)
            WithdrawWay++;
        return;
    }

    // not withdraw nowCourse
    WithdrawClass(nowCourse + 1, nowCredit, nowChosenCourse);

    // withdraw nowCourse
    WithdrawClass(nowCourse + 1, nowCredit - CourseCredit[nowCourse], nowChosenCourse - 1);
}
