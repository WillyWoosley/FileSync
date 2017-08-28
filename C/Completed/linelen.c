#include <stdio.h>

#define MAXLINE 1000

int getinputline(char test[], int max);
void copy(char from[], char to[]);

int main() {

    char cur[MAXLINE], longest[MAXLINE];
    int max, len;
    max = 0;
    
    while ((len = getinputline(cur, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(cur, longest);
            printf("New Max!\n");
        }
        

        for (int i=0; i<len; i++)
            putchar(cur[i]);

        printf("%d characters long\n", len);
    }
    
    printf("Longest: \n");

    for (int i=0; i<max; i++)
        putchar(longest[i]);
    
    printf("Length : %d characters\n", max);

    return 0;
}

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

void copy(char from[], char to[]) {
    int pos=0;

    while ((to[pos]=from[pos]) != '\0')
        pos++;
}
