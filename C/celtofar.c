#include <stdio.h>

main() {
    
    float fahr, cels;
    int aug, upper;

    aug = 20;
    upper = 300;
    cels = 0;
    
    printf("%7s\t%10s\n", "Celsius", "Fahrenheit");

    while (cels <= upper) {
        fahr = (cels * 9.0/5.0) + 32.0;
        printf("%7.0f\t%10.2f\n", cels, fahr);
        cels += 20;
    }
    
}
