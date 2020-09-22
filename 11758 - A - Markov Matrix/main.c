#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        int cityNum;
        scanf("%d", &cityNum);

        int i, j;
        float Markov[5][5];
        float populationNow[5];
        float populationNext[5];
        int target;

        for(i = 0; i < cityNum; i++) {
            for(j = 0; j < cityNum; j++) {
                scanf("%f", &Markov[i][j]);
            }
        }

        for(i = 0; i < cityNum; i++) {
            scanf("%f", &populationNow[i]);
        }

        scanf("%d", &target);

        int years = 0;

        while(populationNow[0] > target) {

            for(i = 0; i < cityNum; i++) {
                float sum = 0;
                for(j = 0; j < cityNum; j++) {
                    sum += Markov[i][j] * populationNow[j];
                }
                populationNext[i] = sum;
            }

            years++;

            if(populationNext[0] == populationNow[0]) {
                years = -1;
                break;
            }

            for(i = 0; i < cityNum; i++) {
                populationNow[i] = populationNext[i];
            }
        }

        if(years != -1)
            printf("%d\n", years);
        else
            printf("Never\n");

    }

    return 0;
}
