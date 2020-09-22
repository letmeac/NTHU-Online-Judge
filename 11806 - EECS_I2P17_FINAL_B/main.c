#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char str[10];
    int frequency;
    int score;
} LNDString; // longest nondecreasing substring

typedef struct
{
    char str[10];
    LNDString* lndStr[10];
    int lndStrNum;
    int points;
} String;

int strNum;
String strList[100];

int lndStrNum;
LNDString lndStrList[1000];

void FindLNDString(String* string);
int cmp(const void *a, const void *b);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    scanf("%d", &strNum);

    int i, j;
    for(i = 0; i < strNum; i++) {
        scanf("%s", strList[i].str);
        strList[i].lndStrNum = 0;
    }

    // find longest nondecreasing substring
    for(i = 0; i < strNum; i++) {
        FindLNDString(&strList[i]);
    }

    // sort by frequency
    LNDString* book[1000];

    for(i = 0; i < lndStrNum; i++) {
        book[i] = &lndStrList[i];
    }

    qsort(book, lndStrNum, sizeof(LNDString*), cmp);

    // attain score
    for(i = 0; i < lndStrNum; i++) {
        book[i]->score = i + 1;
    }

    // attain points
    for(i = 0; i < strNum; i++) {
        strList[i].points = 0;
        for(j = 0; j < strList[i].lndStrNum; j++) {
            strList[i].points += strList[i].lndStr[j]->score;
        }
        printf("%s %d\n", strList[i].str, strList[i].points);
    }

    return 0;
}

void FindLNDString(String* string)
{
    int i, j;
    int length = strlen(string->str);

    int maxLength = 0;
    int subStrCount = 0;
    int subStrPosition[10][2] = {0};

    // find all longest nondecreasing substrings
    for(i = 0; i < length; ) {

        j = i;
        while(j + 1 < length && string->str[j] <= string->str[j + 1]) j++;

        if(j - i + 1 > maxLength) {
            maxLength = j - i + 1;
            subStrCount = 0;
            subStrPosition[subStrCount][0] = i;
            subStrPosition[subStrCount][1] = j;
            subStrCount++;
        }
        else if(j - i + 1 == maxLength) {
            subStrPosition[subStrCount][0] = i;
            subStrPosition[subStrCount][1] = j;
            subStrCount++;
        }

        i = j + 1;
    }

    // add found substrings to the lndStrList
    for(i = 0; i < subStrCount; i++) {

        char subStr[10];
        strncpy(subStr, string->str + subStrPosition[i][0], maxLength);
        subStr[maxLength] = '\0';

        for(j = 0; j < lndStrNum; j++) {
            if(!strcmp(lndStrList[j].str, subStr)) {
                lndStrList[j].frequency++;
                string->lndStr[string->lndStrNum++] = &lndStrList[j];
                break;
            }
        }
        if(j == lndStrNum) {
            strcpy(lndStrList[lndStrNum].str, subStr);
            lndStrList[lndStrNum].frequency = 1;
            string->lndStr[string->lndStrNum++] = &lndStrList[lndStrNum];
            lndStrNum++;
        }
    }
}

int cmp(const void *a, const void *b)
{
    LNDString* lndStr_a = *(LNDString**)a;
    LNDString* lndStr_b = *(LNDString**)b;

    if(lndStr_a->frequency > lndStr_b->frequency) return -1;
    else if(lndStr_a->frequency < lndStr_b->frequency) return 1;
    else return strcmp(lndStr_a->str, lndStr_b->str);
}
