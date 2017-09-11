#include <stdio.h>

#define MAXLEN 1000

int main() {

    int num = 1;
    int seen = 0;
    int index;
    int primes[MAXLEN], pairs[MAXLEN/10]; 
    int isprime;

    primes[seen]=1;
    seen++;

    while (seen <= MAXLEN) {
        //index starts at one since primes[0]=1
        index = 1;
        num++;
        isprime = 1;

        while (index < seen && isprime==1) {
            if (num%primes[index]==0) {
                isprime = 0;
            }
            index++;
        }

        if (isprime == 1) {
            primes[seen]=num;
            seen++;
        }
    
    }

    index = 0;

    while (index < MAXLEN) {
        if (primes[index]+2 == primes[index+1]) {
            printf("Pair: %d %d\n", primes[index], primes[index+1]);
        }
        index++;
    }
//difference
    return 0;
}
