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
    return pow(2, x)+x-4;
}

double solve(double a, double b) {
    double x;
    do {
        x = a -(b-a)*f(a)/(f(b)-f(a));
        if (f(x)*f(a) < 0)
            b = x;
        else
            a = x;
    } while (fabs(f(x)) > EPS);
    return a;
}

int main(int argc, char* argv[]) {
    printf("The solution of the equaltion is: %.3lf\n", solve(1, 2));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
