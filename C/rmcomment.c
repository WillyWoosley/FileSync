//remove all // up until \n
//  account for char c = "//"
//remove all /* until */
// 
//avoid strings by bool singlestar
//
//
//removes everything after //
//avoids // in ""

//removes all /* to */
//avoids /* in strings
//


/*

    another comment bloc
    to test
    this

    function

 */

#include <stdio.h>

#define MAXCHAR 1000

int getinputline(char read[], int max);
int contains(char pass[], char search);

int main() {

    int sinstar = 0, sindash = 0, instr = 0, inbloc = 0;
    int len, testlen, index, offset = 0;
    char input[MAXCHAR], test[MAXCHAR];

    /*while ((len = getinputline(input, MAXCHAR)) > 0) {
        
        while ((index = contains(test, '/')) >= 0 && index < testlen-1) {
           if (test[index+1] == '/') {
                test[index] = '\n';
                test[index+1] = '\0';
                break; 
           } else {
                offset += index;
                copy(test + index + 1, test);
            }
        }


    }*/
   while ((len = getinputline(input, MAXCHAR)) > 0) {
        for (int i=0; i<len; i++) {
            
            if (input[i] == '"') {
                if (instr) {
                    instr = 0;
                } else {
                    instr = 1;
                }
            }
            
            if (instr) {
                continue;
            }

            if (sindash) {
                if (input[i] == '*') {
                    inbloc = 1;
                    input[i-1] = '\n';
                    input[i] = '\0';
                    break;
                } else if (input[i] != '/') {
                    sindash = 0;
                } else {
                    input[i-1] = '\n';
                    input[i] = '\0'; 
                    break;
                }
            } else {
                if (input[i] == '/') {
                    sindash = 1;
                }
            }

            if (input[i] == '*') {
                sinstar = 1;
            }

            if (sinstar) {
                if (input[i] == '/') {
                    inbloc = 0;
                }
            }
        }

        printf("%s", input);

        sindash = 0;
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

void copy(char from[], char to[]) {
    
    int i;

    for (i=0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }

    to[i] = '\0';
}

//Maybe scrap all of this, but write helper function .contains
//int contains(char[]), go until \0 
