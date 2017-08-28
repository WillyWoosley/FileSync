#include <stdio.h>

float celtofar(float temp);

int main() {
    
    float aug, cel;
    aug = 20;
    cel = 0;

    printf("%7s : %7s\n", "Cel", "Fahr");

    while (cel <= 300) {
        printf("%7.1f : %7.1f\n", cel, celtofar(cel));
        cel += aug;
    }

    return 0;
}

float celtofar(float temp) {
    temp = (temp * 9.0/5.0) + 32.0;
    return temp;
}
