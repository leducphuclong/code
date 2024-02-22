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
const double EPS = 1e-5;

// Declare global variables.
// End of global variable declaration.

double f(double x) {
    return pow(x, 3)+x-5;
}

double f1(double x) {
    return 3*pow(x, 2)+1;
}

double solve(double x) {
    double p_x = 100000, prev;
    do {
        prev = p_x-x;
        p_x = x;
        x = x-f(x)/f1(x);
    } while (fabs(p_x-x) >= EPS && fabs(prev) > fabs(p_x-x));
    return x;
}


int main(int argc, char* argv[]) {
    printf("The solution of the equaltion is: %.3lf\n", solve(2));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
