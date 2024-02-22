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

double f(double X[], double Y[], int n, double x) {
    double res = 0, W = 1;
    for (int i = 0; i < n; ++i) {
        W *= (x-X[i]);
        double sum_row = (x-X[i]);
        for (int j = 0; j < n; ++j)
            if (j != i)
                sum_row *= (X[i]-X[j]);
        res += (Y[i]/sum_row);
    }
    return res*W;
}

int main(int argc, char* argv[]) {
    double X[] = {1, 2, 3, 4, 5};
    double Y[] = {3, 2, 7, -1, 0};
    int n = sizeof(X)/sizeof(double);
    printf("Solution: %lf", f(X, Y, n, 3.5));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
