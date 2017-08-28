#include <stdio.h>

int contains(char pass[], char search);
void copy(char from[], char to[]);

int main() {

    char test[] = {'h', 'e', 'l', 'l', 'o', '\n', '\0'};
    char other[20];

    copy(test + 2, test);
    printf("%s", test);

    return 0;
}

/*
 *  function takes a char[] and a char to search for
 *  and returns the index of the char if found
 *  or -1 if not present
 *
 */

int contains(char pass[], char search) {
    for (int i=0; pass[i] != '\0'; i++)
        if (pass[i] == search)
            return i;

    return -1;
}


/*
 *  function takes two char[] and copies the
 *  first into the second, while leaving the first
 *  untouched
 *
 *  expects second char[] to be of equal or greater size to the first
 *
 */

void copy(char from[], char to[]) {
    
    int i;
    
    printf("%s", from);
    printf("%s", to);

    for (i=0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }

    to[i] = '\0';
}
