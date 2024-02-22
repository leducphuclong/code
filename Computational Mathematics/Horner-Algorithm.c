// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

double Horner(double polynomial[], int n, double x, int exp) {
    if (exp == n-2)
        return x*polynomial[n-1]+polynomial[n-2];
    return Horner(polynomial, n, x, exp+1)*x+polynomial[exp];;
}

int main(int argc, char* argv[]) {
    double polynomial[] = {-1, -1, 0, 2, -5, 0, 1};
    int n = sizeof(polynomial)/sizeof(double);
    double x = -2;
    printf("The value of polynomail when x = %.2lf is: %.2lf\n",
     x, Horner(polynomial, n, x, 0));
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
