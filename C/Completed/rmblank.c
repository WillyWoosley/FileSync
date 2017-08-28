#include <stdio.h>

#define TABLEN 4

int main() {

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (int i=0; i<TABLEN; i++)
                putchar(' ');
        else
            putchar(c);
    }

    return 0;
}
