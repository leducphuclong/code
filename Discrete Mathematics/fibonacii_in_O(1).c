// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <math.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

int fibo(int n) {
    double a = 1/sqrt(5)*pow((1+sqrt(5))/2, n-1);
    double b = 1/sqrt(5)*pow((sqrt(5)-1)/2, n-1);
    return a+b;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%i", &n);
    printf("%i\n", fibo(n));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
