#include <stdio.h>

#define MAXCHAR 1000

int getinputline(char read[], int max);

int main() {

    int inbloc=0, incom=0, instr=0;
    int curly=0, square=0, paren=0;
    int index = 0, len;
    char line[MAXCHAR];

    while ((len = getinputline(line, MAXCHAR)) > 0) {
        
        while (index < len) {
            
            //should continue if special conditions are met
            //  could do the continues in an else block
            //  doesn't account for internal parens
            if (instr) {
                if (line[index]=='"') {
                    index++;
                    instr=0;
                }
                continue;
            }

            if (incom) {
                if (line[index]=='\n') {
                    index++;
                    incom=0;
                }
                continue;
            }

            if (inbloc) {
                 

            }

            //segment should remove chars
            if (line[index]==''') {
                if (line[index+1]=='\\') {
                    index+=4;
                } else {
                    index+=3;
                }
            }

            //handles normal char processing 
            if (line[index]=='"') {
                instr=1;
            } else if (line[index]=='\\') {
                if (line[index]=='*') {
                    inbloc=1;
                } else {
                    incom=1;
                }
            } else {
                if (line[index]=='{') {
                    curly++;
                } else if (line[index]=='}') {
                    curly--;
                } else if (line[index]=='(') {
                    paren++;
                } else if (line[index]==')') {
                    paren--;
                } else if (line[index]=='[') {
                    square++;
                } else if (line[index]==']') {
                    square--;
                }
            }

            index++;
               
        }

    }

}

//order of operations
//if special conditions, check to see if they are ended, then do nothing more
//if not in special conditions, check if we are dealing with a char
//if neither of previous two, handle char normally
//  check if char causes anything special to happen

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

