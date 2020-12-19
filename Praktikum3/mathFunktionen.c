#include "stdlib.h"
#include "stdio.h"
#include "konstanten.h"

int isPrime(int zahl){
    int prime = 1;
    for (int i = 2; i*i <= zahl; ++i) {
        if(zahl%i == 0){
            prime = 0;
            break;
        }
    }
    return prime;
}

