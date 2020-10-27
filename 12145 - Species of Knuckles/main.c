#include <stdio.h>

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    int length;
    scanf("%d", &length);

    if(length > 26 || length == 1)
        printf("I'm the god of Knuckles!\n");
    else {
        char str[27];
        scanf("%26s", str);

        int count[26] = {0};
        for(int i = 0; i < length; i++)
            count[str[i] - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(count[i] >= 2) {
                printf("I'm the god of Knuckles!\n");
                return 0;
            }
        }
        printf("Different makes perfect\n");
    }

    return 0;
}
