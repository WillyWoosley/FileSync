#include <stdio.h>

#define MAXLINE 1000
#define MINLENGTH 80

int getinputline(char test[], int max);

int main() {

    char cur[MAXLINE], longest[MAXLINE];
    int len;
    
    while ((len = getinputline(cur, MAXLINE)) > 0)
        if (len > MINLENGTH)
            printf("%s", cur);
    
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

