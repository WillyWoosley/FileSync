#include <stdio.h>

main() {
    
    float fahr, cels;
    int aug, upper;

    aug = 20;
    upper = 300;
    fahr = 0;
    
    printf("%10s\t%7s\n", "Fahrenheit", "Celsius");

    while (fahr <= upper) {
        cels = 5.0/9.0 * (fahr - 32.0);
        printf("%10.0f\t%7.2f\n", fahr, cels);
        fahr += aug;
    }
    
}
