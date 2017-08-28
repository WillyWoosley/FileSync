#include <stdio.h>

#define MAXCHAR 1000
#define FOLDLEN 80

int getinputline(char read[], int max);

int main() {

    int len, index = 0;
    char raw[MAXCHAR], fold[FOLDLEN];

    while ((len = getinputline(raw, MAXCHAR)) > 0) {
        while (len > 0) {
            while (len > 0 && (raw[index] == ' ' || raw[index] =='\t')) {
                index++;
                len--;
            }

            if (len/FOLDLEN > 0) {
                printf("%.*s\n", FOLDLEN, raw + index);
                index += FOLDLEN;
            } else {
                printf("%s", raw + index); 
            }
            len -= FOLDLEN;
        }

        index = 0;
        
    }

    return 0;
}

int getinputline(char read[], int max) {
    
    int len;
    char c;

    for (len = 0; len < max-1 && (c = getchar()) != EOF && c != '\n'; ++len) {
        read[len] = c;
    }

    if (c == EOF) {
        return 0;
    }

    if (c = '\n') {
        read[len] = '\n';
        ++len;
    }

    read[len] = '\0';
    return len;
}

