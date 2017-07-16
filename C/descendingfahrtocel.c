#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define AUG 20

main() {
   
    printf("%10s\t%7s\n", "Fahrenheit", "Celsius");

   for (int fahr=UPPER; fahr>=LOWER; fahr-=AUG) {
       printf("%10d\t%7.2f\n", fahr, (fahr-32)*5.0/9.0);
   }

}
