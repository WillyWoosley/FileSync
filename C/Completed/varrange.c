#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    printf("From headers:\n");
    
    printf("Signed Variables:\n");
    printf("Type, Min, Max\n");
    printf("Char %d %d\n", CHAR_MIN, CHAR_MAX);    
    printf("Short %d %d\n", SHRT_MIN, SHRT_MAX);
    printf("Int %d %d\n", INT_MIN, INT_MAX);
    printf("Long %ld %ld\n", LONG_MIN, LONG_MAX);
    
    printf("Unsigned Variables:\n"); 
    printf("Char %c\n", UCHAR_MAX); 
    printf("SHORT %d\n", USHRT_MAX);
    printf("Int %u\n", UINT_MAX);
    printf("Long %lu\n", ULONG_MAX);
    
    return 0;
}
