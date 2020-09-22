#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int cases;
    scanf("%d", &cases);

    while(cases-- > 0) {

        // valid: 'A', '2', '3', '4', '5', '6', '7', '8', '9', '1'(10), 'J', 'Q', 'K'
        // not valid: '0'
        char card[5] = {'0'};
        int cardCount[5] = {0};
        int newCardEntry = 0;

        int i, j;
        for(i = 0; i < 5; i++) {

            char ch;
            scanf(" %c", &card[newCardEntry]);
            if(card[newCardEntry] == '1') scanf(" %c", &ch);

            int cardAdded = 0;

            for(j = 0; j < newCardEntry; j++) {
                if(card[j] == card[newCardEntry]) {
                    cardCount[j]++;
                    card[newCardEntry] = '0';
                    cardAdded = 1;
                    break;
                }
            }

            if(!cardAdded) {
                cardCount[newCardEntry++]++;
                if(newCardEntry == 4) {
                    while(++i < 5) {
                        scanf(" %c", &ch);
                        if(ch == '1') scanf(" %c", &ch);
                    }
                    break;
                }
            }
        }

        if((cardCount[0] == 3 && cardCount[1] == 2) || (cardCount[0] == 2 && cardCount[1] == 3)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
