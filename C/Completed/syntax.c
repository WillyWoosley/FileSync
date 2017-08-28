#include <stdio.h>

#define MAXCHAR 1000

int format(char line[], int bloc);
int getinputline(char read[], int max);
void rm(char input[], int start, int fin);
void copy(char from[], char to[]);
int contains(char pass[], char search); 

int main() {

    char input[MAXCHAR];
    int len, index, firstindex;
    int curly=0, block=0, paren=0;
    int quote=0, apos=0;
    int errorcount = 0;
    int bloc = 0;
    
    while ((len = getinputline(input, MAXCHAR)) > 0) {
        bloc = format(input, bloc);
        for (int i=0; input[i]!='\0'; i++) {
            if (input[i]=='{') {
                curly++;
            } else if (input[i]=='}') {
                curly--;
            } else if (input[i]=='[') {
                block++;
            } else if (input[i]==']') {
                block--;
            } else if (input[i]=='(') {
                paren++;
            } else if (input[i]==')') {
                paren--;
            } else if (input[i]=='"') {
                quote++;
            } else if (input[i]=='\'') {
                apos++;
            }
        }
    }

    if (curly != 0 || block != 0 || paren !=0 || quote!=0 || apos!=0) {
        printf("Errors found!\n");
        if (curly!=0) {
            if (curly < 0) {
                printf("%d unbalanced curly braces\n", curly * -1);
            } else {
                printf("%d unbalanced curly braces\n", curly);
            }
        }

        if (block!=0) {
            if (block < 0) {
                printf("%d unbalanced block braces\n", block * -1);
            } else {
                printf("%d unbalanced block braces\n", block);
            }
        }

        if (paren!=0) {
            if (paren < 0) {
                printf("%d unbalanced paren braces\n", paren * -1);
            } else {
                printf("%d unbalanced paren braces\n", paren);
            }
        }

        if (quote!=0) {
            if (quote < 0) {
                printf("%d unbalanced quotes\n", quote * -1);
            } else {
                printf("%d unbalanced quotes\n", quote);
            }
        }

        if (apos!=0) {
            if (apos < 0) {
                printf("%d unbalanced apostrophes\n", apos * -1);
            } else {
                printf("%d unbalanced apostrophes\n", apos);
            }
        }
    } else {
        printf("syntax check passed!\n");
    }

}

int format(char line[], int inbloc) {
    
    int start=0;
    int fin=0;
    int instr=0;
    int index, firstindex;

    for (int i=0; line[i]!='\0'; i++) {
        if (line[i]=='"') {
            if (line[i+1]!='\'') {
               if (instr) {
                    instr=0;
                    fin=i;
                    rm(line, start, fin);
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
                rm(line, i, i+3);
            } else {
                rm(line, i, i+2);
            }
        }
    }

    if (inbloc) {

        if ((index = contains(line, '/')) > 0) {
            if (line[index-1]=='*') {
                copy(line+index+1, line);
                inbloc=0;
            }     
        } else {
            line[0]='\0';
        }
    }

    if ((index=contains(line, '/')) > -1) {
        if (line[index+1]=='/') {
            line[index]='\n';
            line[index+1]='\0';
        } else if (line[index+1]=='*') {
            line[index]='\n';
            line[index+1]='\0';
            inbloc = 1;
            firstindex = index;
            if ((index = contains(line+firstindex+2, '*')) > -1) {
                if (line[index+firstindex+3]=='/') {
                    inbloc=0;
                }

            }
        }
    }

    return inbloc;
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

    for (int i=start; i<=fin; i++) {
        input[i]=' ';   
    }

}

void copy(char from[], char to[]) {
    int i;
    for (i=0; from[i]!='\0'; i++) {
        to[i]=from[i];
    }
    to[i]='\0';
}

int contains(char pass[], char search) {
    for (int i=0; pass[i] != '\0'; i++)
        if (pass[i] == search)
            return i;

    return -1;
}


