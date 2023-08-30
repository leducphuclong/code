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
const double EPS = 1e-10;

// Declare global variables.
// End of global variable declaration.

double exp_selfwrite(double x) {
    double res = 1, next = 1;
    int factorial = 0;
    do {
        next = next*x/(++factorial);
        res += next;
    } while (fabs(next) >= EPS);
    return res;
}

double sin_selfwrite(double x) {
    double res = 0, next = x;
    int factorial = 1;
    do {
        res += next;
        next = next*x*x*(-1)/(factorial+1)/(factorial+2);
        factorial += 2;
    } while (fabs(next) >= EPS);
    return res;
}

double cos_selfwrite(double x) {
    double res = 0, next = 1;
    int factorial = 0;
    do
    {
        res += next;
        next = next*x*x/(factorial+1)/(factorial+2)*-1;
        factorial += 2;
    } while (fabs(next) >= EPS);
    return res;
}

int main(int argc, char* argv[]) {
    double x = 10;

    printf("e^x in header file: %lf\n", exp(x));
    printf("e^x self-write: %lf\n", exp_selfwrite(x));

    printf("\nsin(x) in header file: %lf\n", sin(x));
    printf("sin(x) self-write: %lf\n", sin_selfwrite(x));

    printf("\ncos(x) in header file: %lf\n", cos(x));
    printf("cos(x) self-write: %lf\n", cos_selfwrite(x));

    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
