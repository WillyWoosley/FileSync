#include <stdio.h>

#define MAXCHAR 1000

int getinputline(char read[], int max);
int contains(char pass[], char search);

int main() {

    int len, index, offset, firquo, secquo, inbloc;
    char line[MAXCHAR];

    while ((len = getinputline(line, MAXCHAR)) > 0) {
        
        offset = 0;

        while ((index = contains(line + offset, '/')) > -1) {

            //removes all // comments
            if (line[index+offset+1]=='/') {
                line[index+offset]='\n';
                line[index+offset+1]='\0';
                break;
            }



            if (line[index+offset+1]=='*') {
                inbloc = 1;
                line[index+offset] = '\n';
                line[index+offset+1] = '\0';
                break;
            }
            
            offset += index + 1;

        }
        
        printf("%s", line);
        
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

int contains(char pass[], char search) {
    for (int i=0; pass[i] != '\0'; i++)
        if (pass[i] == search)
            return i;

    return -1;
}


