#include <stdio.h>

#define MAXCHAR 1000

int getinputline(char test[], int max);
int rmblank(char rm[]);

int main() {
    
    int len;
    char read[MAXCHAR];

    while (getinputline(read, MAXCHAR) > 0) {
        if (rmblank(read) > 0) {
            printf("%s", read);
        }
    }

    return 0;
}

/*
 *  Reads a line of input and returns its length
 */

int getinputline(char test[], int max) {
    
    int len;
    char c;

    for (len = 0; len < max-1 && (c = getchar()) != EOF && c != '\n'; ++len)
        test[len] = c;

    if (c == EOF)
        return 0;

    if (c = '\n') {
        test[len] = '\n';
        ++len;
    }

    test[len] = '\0';
    return len;
}



/*
 *  Takes a char array and removes all trailing blanks, returning its resulting length
 */

int rmblank(char rm[]) {
    int i;
    i=0;
    
    while (rm[i] != '\n') 
        i++;
    
    i--;

    while (i >= 0 && (rm[i] == ' ' || rm[i] == '\t')) 
        i--;

    if (i >= 0) {
        i++;
        rm[i] = '\n';
        i++;
        rm[i] ='\0';
    }

    return i;
}
