#include <stdio.h>

#define MAXCHAR 1000

int main() {
    
    char read[MAXCHAR];
    int max = MAXCHAR+1;
    int len;
    char c;

    for (len = 0; (c = getchar()) != '\n'; ++len) {
        if (len < max-1) {
            if (c != EOF) {
               read[len] = c; 
            }
        }        
    }

    read[len]='\n';
    read[len+1]='\0';
    printf("%s", read);

    return 0;

}
