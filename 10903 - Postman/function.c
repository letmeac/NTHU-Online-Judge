#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

int compare(const void *a, const void *b)
{
    Letter letter_a = *(Letter*)a;
    Letter letter_b = *(Letter*)b;

    if(letter_a.zipcode < letter_b.zipcode) return -1;
    else if(letter_a.zipcode > letter_b.zipcode) return 1;
    else {

        int weight_a = 0;
        int weight_b = 0;

        int length_a = strlen(letter_a.name);
        int length_b = strlen(letter_b.name);

        int i;

        for(i = 0; i < length_a; i++) {
            if(isupper(letter_a.name[i])) {
                weight_a += letter_a.name[i] - 'A' + 2;
            }
            else if(islower(letter_a.name[i])) {
                weight_a += letter_a.name[i] - 'a' + 1;
            }
        }

        for(i = 0; i < length_b; i++) {
            if(isupper(letter_b.name[i])) {
                weight_b += letter_b.name[i] - 'A' + 2;
            }
            else if(islower(letter_b.name[i])) {
                weight_b += letter_b.name[i] - 'a' + 1;
            }
        }

        if(weight_a < weight_b) return -1;
        else if(weight_a > weight_b) return 1;
        else return strcmp(letter_a.name, letter_b.name);
    }
}
