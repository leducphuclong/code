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
const double EPS = 1e-6;

// Declare global variables.
// End of global variable declaration.

double g(double x) {
    return pow(x+1, (double)1/3);
}

double solve(double x0) {
    double prev_x0 = 100000, prev;
    do {
        prev = prev_x0-x0;
        prev_x0 = x0;
        x0 = g(x0);
    } while (fabs(x0-prev_x0) >= EPS && fabs(prev) > fabs(prev_x0-x0));
    return x0;
}

int main(int argc, char* argv[]) {
    printf("The solution of the equaltion is: %.3lf\n", solve(1));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
