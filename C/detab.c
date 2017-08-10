#include <stdio.h>

#define TABLEN 4

int main() {

    char c;
    int len = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (int i=0; i < TABLEN; i++) {
                putchar(' ');
                len++;
            }
        else {
            putchar(c);
            len++;
        }
    }

    return 0;
}
