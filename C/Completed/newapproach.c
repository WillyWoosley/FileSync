#include <stdio.h>

#define MAXCHAR 1000

void format(char line[]);
int getinputline(char read[], int max);
void rm(char input[], int start, int fin);
void copy(char from[], char to[]);
int contains(char pass[], char search); 

int main() {

    char input[MAXCHAR], mod[MAXCHAR];
    int len, index, firstindex;
    int inbloc = 0;
    
    while ((len = getinputline(input, MAXCHAR)) > 0) {
        copy(input, mod);
        format(mod);
        
        if (inbloc) {
            if ((index = contains(mod, '/')) > 0) {
                if (mod[index-1]=='*') {
                    copy(mod+index+1, mod);
                    copy(input+index+1, input);
                    printf("mod:%sinput:%s", mod, input);
                    inbloc=0;
                }     
            } else {
                input[0]='\0';
            }
        }

        if ((index=contains(mod, '/')) > -1) {
            if (mod[index+1]=='/') {
                input[index]='\n';
                input[index+1]='\0';
            } else if (mod[index+1]=='*') {
                input[index]='\n';
                input[index+1]='\0';
                inbloc = 1;
                printf("%d", index);
                firstindex = index;
                if ((index = contains(mod+firstindex+2, '*')) > -1) {
                    printf("got");
                    if (mod[index+firstindex+3]=='/') {
                        printf("here");
                        inbloc=0;
                    }

                }
                printf("%d", inbloc);
            }
        }

        printf("%s", input);
    }



}

void format(char line[]) {
    
    int start=0;
    int fin=0;
    int instr=0;

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


