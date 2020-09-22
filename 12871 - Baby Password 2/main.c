#include <stdio.h>
#include <ctype.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    char alph;
    int shift;

    scanf("%c %d", &alph, &shift);

    if(islower(alph)) {
        alph = toupper(alph);
        alph = (alph - 'A' - shift + 26) % 26 + 'A';
    }
    else if(isupper(alph)) {
        alph = tolower(alph);
        alph = (alph - 'a' - shift + 26) % 26 + 'a';
    }

    printf("%c\n", alph);

    return 0;
}
