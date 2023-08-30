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

void print_matrix(double mtx[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%3.0lf ", mtx[i][j]);
        printf("\n");
    }
}

void bang_sai_phan(double X[], double Y[], int n) {
    double mtx[100][100];
    for (int i = 0; i < n; ++i)
        mtx[i][0] = Y[i];
    for (int j = 1; j < n; ++j)
        for (int i = j; i < n; ++i)
            mtx[i][j] = mtx[i][j-1]-mtx[i-1][j-1];
    print_matrix(mtx, n);
}

int main(int argc, char* argv[]) {
    double X[] = {1, 2, 3, 4, 5};
    double Y[] = {2, 4, 5, 7, 8};
    int n = sizeof(X)/sizeof(double);
    bang_sai_phan(X, Y, n);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
