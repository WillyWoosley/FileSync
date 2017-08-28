#include <stdio.h>

int main() {

    int c;
    int charfreq[26] = {0};

    while ((c = getchar()) != EOF) {
        if (c != ' ' || c != '\t' || c != '\n') {
            ++charfreq[c-'a'];
        }
    }

    for (int i=0; i<26; i++) {
        for (int j=0; j<charfreq[i]; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
