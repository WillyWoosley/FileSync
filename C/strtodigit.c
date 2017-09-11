#include <stdio.h>

#define MAXLEN 1000

int main() {

    char line[MAXLEN];
    int index = 0;
    unsigned int num = 0;
    char read;

    while ((read = getchar()) != '\n' && read != EOF && index < MAXLEN) {
        line[index] = read;
        index++;
    }

    line[index]='\n';
    index = 0;

    while (line[index] != '\n' && line[index] >= '0' && line[index] <='9') {
        
        if (index==0) {
            num = line[index]-'0';
        } else {
            num = num * 10 + (line[index]-'0');   
        }
        
        index++;
    }

    printf("%d\n", num);

    return 0;
}
