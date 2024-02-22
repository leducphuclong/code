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

double L(double X[], double Y[], int n, double x) {
    double W = 1;
    for (int i = 0; i < n; ++i)
        W *= (x-X[i]);

    double N0 = 0;
    for (int i = 0; i < n; ++i) {
        double sum = Y[i]/(x-X[i]);
        for (int j = 0; j < n; ++j)
            if (j != i)
                sum /= (X[i]-X[j]);
        N0 += sum*W;
    }
    return N0;
}

int main(int argc, char* argv[]) {
    double X[] = {0, 1, 2, 4};
    double Y[] = {2, 3, -1, 0};
    int n = sizeof(X)/sizeof(double);
    printf("Solution: %lf", L(X, Y, n, 2.5));
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
