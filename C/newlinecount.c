#include <stdio.h>

int main() {
    int c, n, b, t, all;
    n = 0;
    b = 0;
    t = 0;
    all = 0;


    while ((c=getchar()) != EOF && c != '%') {
        if (c=='\n') {
            n++;
            all++;
        } 
        
        if (c=='\t') {
            t++;
            all++;
        }

        if (c==' ') {
            b++;
            all++;
        }
    }
        printf("%5.5s %5.5s %5.5s %5.5s\n", "newline", "blank", "tab", "all");
        printf("%5d %5d %5d %5d\n", n, b, t, all); 
        return 0;
}
