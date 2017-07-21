#include <stdio.h>

#define MAXCHAR 1000

void reverse(char s[], int slen);
int getinputline(char readto[], int max);

int main() {

    int len;
    char read[MAXCHAR];

    printf("Intial input: ");

    while ((len = getinputline(read, MAXCHAR)) > 0) {
        reverse(read, len);
        printf("%s", read);
        printf("\nNext Input: ");
    }

    return 0;
}

/*
 *  Reads a line of input into a char array and returns its length
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
 * Takes a character string and reverses it
 */

void reverse(char s[], int slen) {

    char swap;

    //maybe something to do with newlines
    for (int i=0, j=slen-1; i<j; ++i, --j) {
        swap = s[i];
        s[i] = s[j];
        s[j] = swap;
    }
    
  }
