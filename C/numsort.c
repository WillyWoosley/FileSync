#include <stdio.h>

#define MAXLEN 1000

int strtoint(char from[]);
int readline(char line[], int max);
void sort(int nums[], int len);

int main() {
    
    char line[MAXLEN];
    int nums[MAXLEN];
    int index = 0;

    printf("sort will begin on first non-integer entered value\n");

    while (readline(line, MAXLEN) > 0 && (nums[index]=strtoint(line)) >= 0) {
       index++; 
    }

    sort(nums, index);

    return 0;
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

void sort(int nums[], int len) {

    int temp;

    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            if (nums[j]<nums[i]) {
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
            }
        }
        printf("%d\n", nums[i]);
    }

}
