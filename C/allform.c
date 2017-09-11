#include <stdio.h>

#define MAXLEN 1000

int tobinary(int val);
int tohex(int val);
int readline(char line[], int max);
int strtoint(char from[]);

int main() {
    
    char line[MAXLEN];
    int num;

    readline(line, MAXLEN);
    num = strtoint(line);
    
    printf("Binary representation: %d\n", tobinary(num));
    printf("Hex representation: %x\n", tohex(num));

    return 0;
}

    //note: this only will work up to 1023, could try to make it work for larger numbers
int tobinary(int val) {
    
    int div = 1, place = 1;
    int bi = 0b1;

    while (val/div > 1) {
        div = div*2;
        place++;
    }
    
    for (int i=place; i>0; i--) {
        if (i==place) {
            bi = bi*(val/div);
        } else {
            bi = (bi*10)+(val/div);
        }
        
        if (val/div==1) {
            val = val-div;
        }
        div = div/2;
    }

    return bi;

}

int tohex(int val) {
    int div = 1, place = 1;
    int hex = 0x1;

    while (val/div > 16) {
        div = div*16;
        place++;
    }

    for (int i=place; i>0; i--) {
        if (i==place) {
            hex = hex*(val/div);
        } else {
            hex = (hex*16)+(val/div);
        }

        if (val/div>0) {
            val = val % div;
        }

        div = div/16;
    }

    return hex;
}

int readline(char line[], int max) {

    int i;
    char ch;

    for (i=0; i<max-1 && (ch=getchar())!='\n' && ch!=EOF; i++) {
        line[i]=ch;
    }

    line[i]='\n';
    i++;
    line[i]='\0';
    return i;
}

//returns number if found, or -1 if no number was present
int strtoint(char from[]) {

    int num = -1;
    int index = 0;

    while (from[index] >= '0' && from[index] <='9') {
        
         if (index==0) {
             num = from[index]-'0';
         } else {
             num = num * 10 + (from[index]-'0');   
         }
        
         index++;
     }
    
    return num;
}


