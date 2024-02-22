// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <math.h>
#include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant
const double EPS = 1e-9;

// Declare global variables.
// End of global variable declaration.

double polynomial(double x) {
    return pow(2, x)+x-4;
}

int main(int argc, char* argv[]) {
    double left = 1, right = 2, middle, tmp;
    do {
        middle = (left+right)/2;
        tmp = polynomial(middle);
        if (tmp*polynomial(left) < 0) {
            right = middle;
        }
        else
            left = middle;
    } while (fabs(left-right) >= EPS && fabs(tmp) > EPS);
    printf("The solution of the equation is: %lf\n", left);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
