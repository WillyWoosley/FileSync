#include <stdio.h>
#define MAX 45

int main() {

    int c, curlength, largestseen;
    int wordlength[MAX] = {0};
    curlength = largestseen = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' '|| c == '\n' || c == '\t') {
            if (curlength > largestseen) {
                largestseen = curlength;
            }
            ++wordlength[curlength];
            curlength = 0;
            continue;
        }

        curlength++;
    }

    for (int i=1; i<MAX; i++) {
        if (wordlength[i] != 0) {
            printf("%d : ", i);
            for (int j=0; j<wordlength[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}
