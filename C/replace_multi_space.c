#include <stdio.h>

int main() {
    
    int c, last;
    
    while ((c = getchar()) != EOF && c != '%') {
        if (last == ' ' && c == ' ') {
            last = c;
            continue;
        }
        
        last = c;
        putchar(c);
    }

    return 0;
}
