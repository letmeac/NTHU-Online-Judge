#include <stdio.h>

#define MAXPOINT 100

int IsOnTheSameLine(int point1, int point2, int point3, long long x[], long long y[]);
void UpdateLine(int num, int point[], int line[MAXPOINT][MAXPOINT]);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        // record which line has three points passed through
        int line[MAXPOINT][MAXPOINT] = {0};

        int pointNum;
        scanf("%d", &pointNum);

        int i, j, k;
        long long x[MAXPOINT], y[MAXPOINT];
        for(i = 0; i < pointNum; i++) {
            scanf("%lld %lld", &x[i], &y[i]);
        }

        int lineNum = 0;

        // total n(n-1)/2 lines
        for(i = 0; i < pointNum; i++) {
            for(j = i + 1; j < pointNum; j++) {

                // if there is a line have not been find as a three-point line,
                // use this line to find if there are other points on that line
                if(!line[i][j]) {

                    // record all the points on this line
                    int sameLinePoint[pointNum];
                    int sameLinePointNum = 2;
                    sameLinePoint[0] = i;
                    sameLinePoint[1] = j;

                    // test all the rest point
                    for(k = j + 1; k < pointNum; k++) {

                        // ignore those already is a three-point line
                        if(!line[i][k]) {
                            if(IsOnTheSameLine(i, j, k, x, y)) {
                                sameLinePoint[sameLinePointNum++] = k;
                            }
                        }
                    }

                    // update all point-to-point as a three-point line
                    if(sameLinePointNum >= 3) {
                        lineNum++;
                        UpdateLine(sameLinePointNum, sameLinePoint, line);
                    }
                }

            }
        }

        printf("%d\n", lineNum);
    }

    return 0;
}

int IsOnTheSameLine(int point1, int point2, int point3, long long x[], long long y[])
{
    // (x[point1] - x[point2]) / (y[point1] - y[point2]) == (x[point2] - x[point3]) / (y[point2] - y[point3])
    return (x[point1] - x[point2]) * (y[point2] - y[point3]) == (x[point2] - x[point3]) * (y[point1] - y[point2]);
}

void UpdateLine(int num, int point[], int line[MAXPOINT][MAXPOINT])
{
    int i, j;
    for(i = 0; i < num; i++) {
        for(j = i + 1; j < num; j++) {
            line[point[i]][point[j]] = 1;
        }
    }
}
