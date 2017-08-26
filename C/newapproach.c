#include <stdio.h>

#define MAXCHAR 1000

void format(char line[]);
int getinputline(char read[], int max);
void rm(char input[], int start, int fin);
void copy(char from[], char to[]);
int contains(char pass[], char search); 

int main() {

    char input[MAXCHAR], mod[MAXCHAR];
    int len, index;
    int inbloc = 0;

    while ((len = getinputline(input, MAXCHAR)) > 0) {
        copy(input, mod);
        format(mod);
        //at this point we are left with two strings, one raw, one formatted
        //to exclude strings and chars, to allow more streamlined searching
        
        //this is where bloc processing should occur
        
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
                printf("%d", inbloc);
                //this logic is broken, revolves around the contains function
                //returning the index of passed array, not of original array
                //can be got arround by addition
                //also revolves around that index is the index of the / in /*, contains needs to start later
                if ((index=contains(mod+index, '*')) > -1 && mod[index+index+1]=='/') {
                    inbloc=0;
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


