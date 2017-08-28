#include <stdio.h>

/*
 * TESTS:
 * nothing
 * "nothing" abc
 * not "things
 * "not" a "thing" here
 * test '"' char
 * test '"' "char" again
 * "test" '"' once more
 * "and" '"' "again"
 * "and" '\\' again
 */

//Works, just needs to be set so that it will recurse and remove multiple strings from the ssame line

#define MAXCHAR 1000

int getinputline(char read[], int max);
void rm(char input[], int start, int fin);

int main() {

    int len;
    int start, fin;
    int instr;
    char line[MAXCHAR];

    while ((len=getinputline(line, MAXCHAR)) > 0) {
        
        start=0;
        fin=0;
        instr=0;

        for (int i=0; line[i]!='\0'; i++) {
            if (line[i]=='"') {
                if (line[i+1]!='\'') {
                    if (instr) {
                        instr=0;
                        fin=i;
                        printf("%d, %d\n", start, fin);
                        rm(line, start, fin+1);
                        i=0;

                    } else {
                        instr=1;
                        start=i;
                    }
                }
            }
        }

        for (int i=0; line[i]!='\0'; i++) {
            if (line[i]=='\'') {
                if (line[i+1]=='\\') {
                    rm(line, i, i+4);
                } else {
                    rm(line, i, i+3);
                }
            }
        }
        

    
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

void rm(char input[], int start, int fin)  {
    int i, j;

    for (i=start, j=fin; input[j]!='\0'; i++, j++) {
        input[i]=input[j];
    }

    input[i]='\0';
    printf("%s", input);

}
